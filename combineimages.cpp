#include "combineimages.h"

CombineImages::CombineImages(QObject *parent) :
    QObject(parent)
{
}

int CombineImages::processImages(QString left, QString right, QString dest) {
	QDir leftDirectory(left);
	QDir rightDirectory(right);
	QDir finalDirectory(dest);

	// check if left and right directories exist
	if (!leftDirectory.exists() || !rightDirectory.exists())
		return 0; // failed

	// check to see if destination directory exists
	if (!finalDirectory.exists()) {
		cout << "Final directory does not exist, Attempting to create." << endl;
		if (!finalDirectory.mkdir(finalDirectory.absolutePath())) { // create it
			cout << "Unable To create final directory \"" << dest.toStdString() << "\"" << endl;
			return 0; // creating directory failed
		} else {
			cout << "Directory \"" << dest.toStdString() << "\" created successfully" << endl;
		}
	}

	// build file list
	filenames = leftDirectory.entryList(QStringList("*.jpg"), QDir::Files|QDir::NoDotAndDotDot);

	// start combining images
	for (int i = 0; i < filenames.size(); i++) {
		cout << QString(filenames.at(i)).toStdString() << endl;
		QImage leftIm, rightIm;
		leftIm.load(leftDirectory.absolutePath()+"/"+filenames.at(i));
		rightIm.load(rightDirectory.absolutePath()+"/"+filenames.at(i));

		QImage finalIm(leftIm.width()+rightIm.width(), leftIm.height(), leftIm.format());
		QPainter painter(&finalIm);

		QTransform trans;
		trans.rotate(180, Qt::ZAxis);

		painter.fillRect(finalIm.rect(), Qt::SolidPattern);
		painter.drawImage(QPoint(0,0),rightIm);
		painter.drawImage(QPoint(rightIm.width(), 0), leftIm.transformed(trans));

		finalIm.save(finalDirectory.absolutePath()+"/"+filenames.at(i));

	}

	return 1;
}

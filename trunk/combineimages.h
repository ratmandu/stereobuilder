#ifndef COMBINEIMAGES_H
#define COMBINEIMAGES_H

#include <QObject>
#include <QImage>
#include <QPainter>
#include <QDir>
#include <QApplication>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class CombineImages : public QObject
{
    Q_OBJECT
public:
    explicit CombineImages(QObject *parent = 0);
	int processImages(QString left, QString right, QString dest);

private:

	QStringList filenames;

signals:

public slots:

};

#endif // COMBINEIMAGES_H

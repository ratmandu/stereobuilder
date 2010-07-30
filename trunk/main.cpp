#include <QtCore/QCoreApplication>
#include <QStringList>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "combineimages.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	QStringList args;
	args = a.arguments();

	if (args.size() < 4) {
		cout << "Usage:" << endl;
		cout << "StereoBuilder /path/to/left /path/to/right /path/to/destination" << endl;
		return 0;
	}



	CombineImages imageProc;
	return imageProc.processImages(args.at(1), args.at(2), args.at(3));

    return a.exec();
}

#ifndef CPROCESSINGTHREAD_HPP
#define CPROCESSINGTHREAD_HPP
#include <QThread>

class CprocessingThread : public QThread
{
	//Q_OBJECT

public:
	CprocessingThread();
	virtual ~CprocessingThread();

	void run();

	QString srcDir;
	QString destDir;
	bool DEbugState;
	int treshold;
	bool comicMode;
	bool findDividedWords;
	int width;
	int height;
	int margin;
	int fontHeight;
	bool hardMargins;
	bool noUpscalling;
	bool fullColor;
	bool justify;
	bool rotateImages;
	QString fileNamePrefix;
	int status;
	bool work;

	QObject * progressBarSignalReciever;

};

#endif // CPROCESSINGTHREAD_HPP

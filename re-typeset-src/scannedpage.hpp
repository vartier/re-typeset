// Re-Typeset program for converting scanned documents to smaller size of page
// without changing text size.
//
// Copyright (C) 2013-2015 Piotr Mika (piotr.mt.mika@gmail.com).
//
// This  program is free software:  you can  redistribute it and/or  modify it
// under the terms of the  GNU General Public License as published by the Free
// Software Foundation,  either version 3 of the License,  or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY  WARRANTY;  without  even the implied  warranty  of MERCHANTABILITY  or
// FITNESS FOR  A PARTICULAR  PURPOSE.  See the GNU General Public License for
// more details.
//
// You should have received a copy of the  GNU  General  Public  License along
// with this program. If not, see <http://www.gnu.org/licenses/>.

#ifndef SCANNEDPAGE_HPP
#define SCANNEDPAGE_HPP
#include "scannedline.hpp"
#include <QImage>
#include <QFile>

class CscannedPage {
public:
	enum EpageNumber { None, Top, Bottom };
	CscannedPage();
	CscannedPage( QString fileMono, QString fileColor );
	/*
	 *Pierwszy etap przetwarzania: podział na linie
	 */
	void getLinesAndHeights( Cstats & stats );
	/*
	 *Drugi etap: dołączenie odciętych kropek
	 */
	void reConnectDots( CstatsPack stats );
	/*
	 *Trzeci etap: zbyt wysokie linie będą rozbite
	 */
	void trimDivideLines( CstatsPack stats );

	void connectDescriptionsToImages( CstatsPack stats );

	void findParagraphs( CstatsPack stats );

	void findDividedWords();

	void checkNumberHeader( CstatsPack stats, CstatsNumberHeader & numHead );

	void setNumberHeader( CstatsPack stats, EpageNumber number, bool header_ );

	void printDEbugImages( CstatsPack stats );

	void getNumHead(CstatsPack stats, CprintedLine & numHead, double scalingRatio, int maxWordLength, bool fullColor=false );
	bool getParagraph(CstatsPack stats, CprintedLine & paragraph, double scalingRatio, int maxWordLength, bool fullColor=false );//false==page completed

	void removeMonoImage();
protected:
	QString fileMono_;
	QString fileColor_;
	QVector < CscannedLine > lines_;
	int processedLine_;
	CscannedLine header_;
	CscannedLine pageNumber_;


};

#endif // SCANNEDPAGE_HPP

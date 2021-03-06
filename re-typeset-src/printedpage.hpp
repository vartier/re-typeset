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

#ifndef PRINTEDPAGE_HPP
#define PRINTEDPAGE_HPP
#include <QImage>
#include "consts.hpp"
#include "stats.hpp"
#include "printedline.hpp"
#include "printedpagestat.hpp"
#include "printedpixelfont.hpp"
#include <QPair>
#include <QDateTime>

class CprintedPage
{
public:
	CprintedPage();
	virtual ~CprintedPage();
	CprintedPage( int width, int height, int margin, int fontHeight, bool justify, bool rotateImages,
				  bool comicMode, bool DEbugState=false );

	void addNumberHeader( CprintedLine & numHead, int srcPageNum );

	bool addParagraph(CprintedLine & paragraph );//false == whole paragraph used

	bool printLastLine();

	void saveAndClear(QString fileName , bool hardMargins);

	bool printImagesFromQueue( bool final=false );

	void addProgressBarsForAllPages();

	int numTocItems();

	void createTitlePage(QVector<QPair<QPair<int, int>, CprintedLine> > & toc );

protected:
	int margin_;
	int lineHeight_;
	int spaceToNextLine_;
	QImage * image_;
	int cursorX;
	int cursorY;
	CprintedLine line_;
	CprintedLine imageQueue_;
	QImage dividedWord_;
	bool isDividedWord_;
	bool justify_;
	bool rotateImages_;
	bool disableProgressBar;
	int srcPageNum_;

	int outLastPage_;
	bool comicMode_;
	bool DEbugState_;
	QVector< CprintedPageStat > outStat_;

	QImage join( const QImage & a, const QImage & b );


};

#endif // PRINTEDPAGE_HPP

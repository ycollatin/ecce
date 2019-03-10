/*           reglevg.cpp       */
/*
 *  This file is part of PRAELECTOR
 *
 *  PRAELECTOR is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  PRAELECTOR is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with PRAELECTOR; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * © Yves Ouvrard, 2009 - 2019
 */

#include "reglevg.h"
#include <QDebug>


RegleVG::RegleVG(QString l)
{
    QChar sep = ';';
    if (l.contains('>')) sep = '>';
    _a = QRegExp(l.section(sep,0,0));
    _b = l.section(sep,1,1);
    _ci = sep == '>';
}

QRegExp RegleVG::a()
{
    return _a;
}

QString RegleVG::b()
{
    return _b;
}

bool RegleVG::ci()
{
    return _ci;
}

QString RegleVG::doc()
{
    QString ret = "%1;%2";
    if (_ci) ret = "%1>%2";
    return ret.arg(_a.pattern()).arg (_b);
}

QString RegleVG::transf(QString s)
{
    if (_a.pattern() == "h" && s.contains("trahe"))
        return s;
    return s.replace(_a, _b);
}

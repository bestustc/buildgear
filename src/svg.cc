/*
 * This file is part of Build Gear.
 *
 * Copyright (c) 2011-2013  Martin Lund
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include "config.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string.h>
#include "buildgear/config.h"
#include "buildgear/svg.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void CSvg::open(string filename)
{
   file = fopen(filename.c_str(), "w");
   if (!file)
   {
      cout << "\nError: Could not open file " << filename << endl;
      cout << strerror(errno) << endl;
      exit(EXIT_SUCCESS);
   }
}

void CSvg::close(void)
{
   fclose(file);
}

void CSvg::addNaked(string content)
{
   fprintf (file, "%s\n", content.c_str());
}

void CSvg::addText(string text, float x, float y, string color, string params)
{
   addText(text, to_string(x), to_string(y), color, params);
}

void CSvg::addText(string text, string x, string y, string color, string params)
{
   fprintf (file,
   "<text x='%s' y='%s' font-family='Verdana' font-weight='bold' fill='%s' %s>%s</text>\n",
   x.c_str(), y.c_str(), color.c_str(), params.c_str(), text.c_str());
}

void CSvg::addText(string text, float x, float y, string color)
{
   addText(text, to_string(x), to_string(y), color);
}

void CSvg::addText(string text, string x, string y, string color)
{
   fprintf (file,
   "<text x='%s' y='%s' font-family='Verdana' font-size='7' font-weight='bold' fill='%s'>%s</text>\n",
   x.c_str(), y.c_str(), color.c_str(), text.c_str());
}

void CSvg::addHeader(float distance)
{
   fprintf (file,
   "<svg version='1.1' xmlns='http://www.w3.org/2000/svg'>\n"
   "<!-- Autogenerated by Build Gear v%s (http://www.buildgear.org/) -->\n"
   "<defs>\n"
   "  <marker id='endArrow' viewBox='0 0 10 10' refX='80' refY='5' markerUnits='strokeWidth' orient='auto' markerWidth='5' markerHeight='4'>\n"
   "     <polyline points='0,0 10,5 0,10 1,5' fill='black' />\n"
   "  </marker>\n"
   "  <marker id='endArrow2' viewBox='0 0 10 10' refX='7' refY='5' markerUnits='strokeWidth' orient='auto' markerWidth='5' markerHeight='4'>\n"
   "     <polyline points='0,0 10,5 0,10 1,5' fill='black' />\n"
   "  </marker>\n"
   "</defs>\n"
   "<rect x='0' y='0' width='%f' height='%f' style='fill:white'/>\n"
   "<text x='10' y='10' fill='black' font-family='Verdana' font-size='7' font-weight='bold' text-anchor='left'>Build Gear - Dependency Chart</text>\n"
   "<g transform='translate(%f,%f)'>\n"
   "   <rect x='0' y='0' width='92' height='6' stroke='black' fill='none' stroke-width='0.3'/>"
   "   <circle cx='8' cy='3' r='2' fill='%s'/>\n"
   "   <text x='11' y='4' fill='black' font-family='Verdana' font-size='3' text-anchor='left'>native build</text>\n"
   "   <circle cx='36' cy='3' r='2' fill='%s'/>\n"
   "   <text x='39' y='4' fill='black' font-family='Verdana' font-size='3' text-anchor='left'>cross build</text>\n"
   "   <line x1='61' y1='3' x2='65' y2='3' stroke='black' stroke-width='0.5' marker-end='url(#endArrow2)'/>\n"
   "   <text x='68' y='4' fill='black' font-family='Verdana' font-size='3' text-anchor='left'>dependency</text>\n"
   "</g>\n"
   "<g transform='translate(%f,%f)'>\n"
   , VERSION
   , 2*distance, 2*distance
   , distance-46, 2*distance-10
   , SVG_COLOR_NATIVE
   , SVG_COLOR_CROSS
   , distance, distance
   );
}

void CSvg::addArrow(float x1, float y1, float x2, float y2)
{
   fprintf (file,
   "   <line x1='%f' y1='%f' x2='%f' y2='%f' stroke='black' stroke-width='0.5' marker-end='url(#endArrow)'/>\n"
   , x1, y1, x2, y2
   );
}

void CSvg::addCircle(float x, float y, string name, string version, string color, int stroke_dash)
{
   fprintf (file,
   "   <circle cx='%f' cy='%f' r='14' stroke='black' stroke-width='0.5' style='stroke-dasharray: 2,%d' fill='%s'/>\n"
   "   <text x='%f' y='%f' fill='black' font-family='Verdana' font-size='3' text-anchor='middle'>%s</text>\n"
   "   <text x='%f' y='%f' fill='black' font-family='Verdana' font-size='3' text-anchor='middle'>%s</text>\n"
   , x, y, stroke_dash, color.c_str()
   , x, y, name.c_str()
   , x, y+3.5, version.c_str()
   );
}

void CSvg::addRectangle(float x, float y, float width, float height, string style)
{
   addRectangle(to_string(x), to_string(y), to_string(width), to_string(height), style);
}

void CSvg::addRectangle(string x, string y, string width, string height, string style)
{
   fprintf (file,
   "  <rect x='%s' y='%s' width='%s' height='%s' style='%s'/>\n"
   , x.c_str(), y.c_str(), width.c_str(), height.c_str(), style.c_str()
   );
}

void CSvg::addLine(float x1, float y1, float x2, float y2, string style)
{
   addLine(to_string(x1), to_string(y1), to_string(x2), to_string(y2), style);
}

void CSvg::addLine(string x1, string y1, string x2, string y2, string style)
{
   fprintf (file,
   "<line x1='%s' y1='%s' x2='%s' y2='%s' style='%s'/>\n",
   x1.c_str(), y1.c_str(), x2.c_str(), y2.c_str(), style.c_str()
   );
}

void CSvg::addFooter(void)
{
   fprintf(file,
   "</g>\n"
   "</svg>\n"
   );
}

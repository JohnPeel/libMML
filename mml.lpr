{
	This file is part of the Mufasa Macro Library (MML)
	Copyright (c) 2009-2012 by Raymond van Venetië and Merlijn Wajer

    MML is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libMML is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libMML.  If not, see <http://www.gnu.org/licenses/>.

	See the file COPYING, included in this distribution,
	for details about the copyright.

    Main project file for libMML.
}
library mml;

{$mode objfpc}{$H+}

uses
  Classes,

  // MML
  bitmaps, Client, colour_conv, dtm, dtmutil, files, finder, fontloader,
  IOManager, mmath, mufasabase, MufasaTypes, mufasatypesutil, ocr, ocrutil,
  os_linux, os_windows, libloader, tpa,

  // IOManager needed classes
  graphics;

{$include mml_client.inc}
{$include mml_iomanager.inc}
{$include mml_files.inc}
{$include mml_finder.inc}

end.


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

  // OS-agnostic MML
  bitmaps, Client, dtm, files, finder, fontloader, IOManager, MufasaTypes, ocr

  // OS-specific MML
  {$IFDEF MSWINDOWS}, os_windows{$ENDIF}
  {$IFDEF LINUX}, os_linux{$ENDIF}

  // IOManager needed classes
  , graphics;

{$define extdecl:=}

{$include mml_client.inc}
{$include mml_iomanager.inc}
{$include mml_files.inc}
{$include mml_finder.inc}
{$include mml_bitmaps.inc}
{$include mml_dtms.inc}
{$include mml_ocr.inc}
{$include mml_fonts.inc}

end.


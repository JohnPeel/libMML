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

    Font wrappers for libMML.
}

{%MainUnit mml.lpr}

  {TMFont = class(TObject)
  public
    Name: String;
    Data: TOcrData;
    constructor Create;
    destructor Destroy; override;
    function Copy: TMFont;
  end;
  { TMFonts }

  TMFonts = class(TObject)
  public
    constructor Create(Owner : TObject);
    destructor Destroy; override;
    function GetFont(const Name: String): TOcrData;
    function FreeFont(const Name: String): Boolean;
    function LoadFont(const Name: String; Shadow: Boolean): boolean;
    function LoadSystemFont(const SysFont : TFont; const FontName : string) : boolean;
    function IsFontLoaded(const Name: String): boolean;
    function Copy(Owner : TObject): TMFonts;
    function Count : integer;
    property Path : string read GetPath write SetPath;
    property Font[Index : integer]: TMfont read GetFontByIndex; default;
  end;  }

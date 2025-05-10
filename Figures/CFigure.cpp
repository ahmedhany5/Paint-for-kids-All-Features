#include "CFigure.h"

int CFigure::LastID = 0;

CFigure::CFigure()
{
	Selected = false;
	
	LastID++;
	ID = LastID;
	RefCount = 0;
}

CFigure::CFigure(GfxInfo FigureGfxInfo) : CFigure()
{
	FigGfxInfo = FigureGfxInfo; // Default status is non-filled.
}


void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

color CFigure::getColor()
{
	return FigGfxInfo.FillClr;
}
bool CFigure::isFilled() const
{
	return FigGfxInfo.isFilled;
}
int CFigure::getID() const
{
	return ID;
}
string CFigure::getTypeName() const
{
	return TypeName;
}
string CFigure::getColorName()
{
	return FigGfxInfo.FillClr.ReturnColor();
}
color CFigure::getBorderColor() const
{
	return FigGfxInfo.DrawClr;
}
void CFigure::ResetID()
{
	LastID = 0;
}

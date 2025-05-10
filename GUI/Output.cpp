#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 65;
	UI.LineUnderTBWidth = 2;

	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	//DONE: Prepare images for each menu item and add it to the list
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Rectangle.jpg";
	MenuItemImages[ITM_SQ] = "images\\MenuItems\\Square.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Triangle.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Hexagon.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Circle.jpg";
	MenuItemImages[ITM_select] = "images\\MenuItems\\Select.jpg";
	MenuItemImages[ITM_filling] = "images\\MenuItems\\filling.jpg";
	MenuItemImages[ITM_ChangeBorder] = "images\\MenuItems\\Changeborder.jpg";
	MenuItemImages[ITM_delete] = "images\\MenuItems\\Delete.jpg";
	MenuItemImages[ITM_clear] = "images\\MenuItems\\Clear.jpg";
	MenuItemImages[ITM_copy] = "images\\MenuItems\\Copy.jpg";
	MenuItemImages[ITM_cut] = "images\\MenuItems\\Cut.jpg";
	MenuItemImages[ITM_paste] = "images\\MenuItems\\Paste.jpg";
	MenuItemImages[ITM_sendforward] = "images\\MenuItems\\SendForward.jpg";
	MenuItemImages[ITM_bringback] = "images\\MenuItems\\BringBack.jpg";
	MenuItemImages[ITM_save] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_load] = "images\\MenuItems\\Load.jpg";
	MenuItemImages[ITM_switchtoplay] = "images\\MenuItems\\Switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///DONE: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_Type] = "images\\MenuItems\\FigureType.jpg";
	MenuItemImages[ITM_FillColour] = "images\\MenuItems\\FillColour.jpg";
	MenuItemImages[ITM_TypeAndFillColour] = "images\\MenuItems\\TypeAndFillColour.jpg";
	MenuItemImages[ITM_switchtodraw] = "images\\MenuItems\\SwitchToDraw.jpg";
	
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, 0);
}

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
color Output::getBackgrndColor() const
{	return UI.BkGrndColor;  }
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}

void Output::DrawTRI(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawCIRCLE(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	double Radius = sqrt(pow(P1.y - P2.y, 2) + pow(P1.x - P2.x, 2));
	// detect radius of circle by distance rule
	pWind->DrawCircle(P1.x, P1.y, Radius, style);

}
void Output::DrawHEX(Point P1, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;
	int vertex = 6;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;
	const int w = 100;
	int x[6] = { P1.x - w , P1.x - (w / 2),P1.x + (w / 2),P1.x + w,P1.x + (w / 2),P1.x - (w / 2) };
	int y[6] = { P1.y ,P1.y - (w * sqrt(3) / 2), P1.y - (w * sqrt(3) / 2) , P1.y,P1.y + (w * sqrt(3) / 2),P1.y + (w * sqrt(3) / 2) };
	pWind->DrawPolygon(x, y, vertex, style);


}

void Output::DrawSQ(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle((P1.x) - 50, (P1.y) - 50, (P1.x) + 50, (P1.y) + 50, style);
}


void Output::SetPlayActionSoundState(bool State)
{
	PlayActionSoundEnabled = State; // Sets the state of the play action sound

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}


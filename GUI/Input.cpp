#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetString(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

int Input::Getnumber(int num)
{
	int number;
		;
	//pWind->WaitKeyPress();

	return 0;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQ: return DRAW_SQ;
			case ITM_TRI: return DRAW_TRI;
			case ITM_HEX: return DRAW_HEX;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case ITM_select: return SELECT;
			case ITM_filling: return filling;
			case ITM_ChangeBorder: return ChangeBorder;
			case ITM_delete: return TO_DELETE;
			case ITM_clear: return CLEAR;
			case ITM_copy: return COPY;
			case ITM_cut: return CUT;
			case ITM_paste: return PASTE;
			case ITM_sendforward: return sendforward;
			case ITM_bringback: return sendbackward;
			case ITM_save: return SAVE;
			case ITM_load: return LOAD;
			case ITM_switchtoplay: return TO_PLAY;
			case ITM_EXIT: return EXIT;	
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///DONE:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{

			case ITM_Type: return pickbytype;
			case ITM_FillColour: return pickbycolor;
			case ITM_TypeAndFillColour: return pickbyboth;
			case ITM_switchtodraw: return TO_DRAW;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;	//just for now. This should be updated
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}

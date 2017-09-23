#include <wx/wx.h>
#include "main.h"
#include "IMG.h"

wxIMPLEMENT_APP(IMG);


bool IMG::OnInit()
{
	Frame_IMG *img = new Frame_IMG();
	img->Show();

	return true;
}


int IMG::OnExit()
{
	return 0;
}

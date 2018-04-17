#ifndef MYAPP_H
#define MYAPP_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "MainFrame.hpp"



class MyApp : public wxApp{ //dérivée de wxApp
	public:
		virtual bool OnInit();
	protected:
		MainFrame *myWindow;

};


DECLARE_APP(MyApp); // déclaration en classe principale


#endif
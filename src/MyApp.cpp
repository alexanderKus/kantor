#include "../include/MyApp.h"
#include "../include/MyFrame.h"

// Inicjalizacja calego programu

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "Kantor", wxDefaultPosition, wxSize(600, 700));
    frame->Show( true );
    return true;
}
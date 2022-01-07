#include "../include/MyFrame.h"
#include "../include/LoadData.h"

// Talica przypisac zdarzen do elementow okna
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_BUTTON(ID_BTN1, MyFrame::OnButtonClicked1)
    EVT_CHOICE(ID_Choice1, MyFrame::CurrencySelected1)
    EVT_CHOICE(ID_Choice2, MyFrame::CurrencySelected2)
wxEND_EVENT_TABLE()

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // Tworzenie paska menu
    wxMenu *menuFile = new wxMenu;
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to Kantor!");

    // Inicjalizacja tablicy walut
    currencies.Add("Euro");
    currencies.Add("PLN");
    currencies.Add("Dolar");
    currencies.Add("Funt");

    // Vectory przechowujace wartosci przewalutowan
    EurToOthers = read_csv("EuroToOthers.csv");
    PlnToOthers = read_csv("PlnToOthers.csv");
    DolarToOthers = read_csv("DolarToOthers.csv");
    FuntToOthers = read_csv("FuntToOthers.csv");


    // Tworzenie planli
    m_top_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(600, 300));
    m_top_panel->SetBackgroundColour(wxColor(48, 56, 59));
    m_mid_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    m_mid_panel->SetBackgroundColour(wxColor(48, 56, 59));
    m_bottom_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(600, 300));
    m_bottom_panel->SetBackgroundColour(wxColor(48, 56, 59));

    // Torzenie pola tekstowego
    m_txt1 = new wxTextCtrl(m_top_panel, ID_TXT1, "100", wxPoint(150, 100), wxSize(300, 100));
    
    // Towrzenie listy walut
    m_ch1 = new wxChoice(m_mid_panel, ID_Choice1, wxPoint(150, 0), wxDefaultSize, currencies);
    m_ch2 = new wxChoice(m_mid_panel, ID_Choice2, wxPoint(370, 0), wxDefaultSize, currencies);

    // Tworzenia przycicku
    m_btn1 = new wxButton(m_bottom_panel, ID_BTN1, "Przelicz", wxPoint(200, 100), wxSize(200, 100));

    // Torzenie box'erow i przypisane do kazdego po jednum panelu
    m_top_box = new wxBoxSizer(wxVERTICAL);
    m_top_box->Add(m_top_panel, 1, wxEXPAND | wxLEFT | wxRIGHT, 5);

    m_mid_box = new wxBoxSizer(wxHORIZONTAL);
    m_mid_box->Add(m_mid_panel, 1, wxEXPAND | wxLEFT | wxRIGHT, 5);

    m_bottom_box = new wxBoxSizer(wxVERTICAL);
    m_bottom_box->Add(m_bottom_panel, 1, wxEXPAND | wxLEFT | wxRIGHT, 5);

    // Towrzenie jednego glownego boxera
    m_box = new wxBoxSizer(wxVERTICAL);

    m_box->Add(m_top_box, 1, wxEXPAND | wxALL);
    m_box->Add(m_mid_panel, 1, wxEXPAND | wxALL);
    m_box->Add(m_bottom_box, 1, wxEXPAND | wxALL);

    this->SetSizerAndFit(m_box);
}

// Funkcja obslugujaca zamkniecie okna
void MyFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}

// Funkcja obslugujaca przycik about
void MyFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("Kantor wersja: v1.0.0\nAutor: Aleksander Kus",
                 "About Kantor", wxOK | wxICON_INFORMATION);
}

// Funkcja obslugujaca przcyik Hello
void MyFrame::OnHello(wxCommandEvent &event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

// Funkcja zdarzeniowa dla przyuciusku
void MyFrame::OnButtonClicked1(wxCommandEvent &event)
{
    // Pobranie wartosci z pola
    wxString number(m_txt1->GetValue());
    wxString finale_value;

    // Zamiana tej wartosci na double
    if( !number.ToDouble(&amount))
    {
        std::cerr << "Cos nie tak\n";
        exit(1);
    }
    float result = 0;
    if (amount > 0){
        result = count(m_ch1_index, m_ch2_index, (float) amount);
    }
    finale_value << result;
    wxLogMessage( finale_value );
    event.Skip();
}

// Funkcja zdarzeniowa dla lity walut
void MyFrame::CurrencySelected1(wxCommandEvent &event)
{
    m_ch1_index = 0;
    m_ch1_index = m_ch1->GetSelection();
    event.Skip();
}

// Funkcja zdarzeniowa dla lity walut
void MyFrame::CurrencySelected2(wxCommandEvent &event)
{
    m_ch2_index = 0;
    m_ch2_index = m_ch2->GetSelection();
    event.Skip();
}

// Funkcja liczba wartosc wypadkowa
float MyFrame::count(unsigned int c1,unsigned int c2, float a)
{

    float converter = 1.0;
    switch (c1)
    {
    case 0:
        switch (c2)
        {
        case 0:
            converter = EurToOthers[0];
            break;
        case 1:
            converter = EurToOthers[1];
            break;
        case 2:
            converter = EurToOthers[2];
            break;
        case 3:
            converter = EurToOthers[3];
            break;
        }
        break;  
    case 1:
        switch (c2)
        {
        case 0:
            converter = PlnToOthers[0];
            break;
        case 1:
            converter = PlnToOthers[1];
            break;
        case 2:
            converter = PlnToOthers[2];
            break;
        case 3:
            converter = PlnToOthers[3];
            break;
        }
        break;
    case 2:
        switch (c2)
        {
        case 0:
            converter = DolarToOthers[0];
            break;
        case 1:
            converter = DolarToOthers[1];
            break;
        case 2:
            converter = DolarToOthers[2];
            break;
        case 3:
            converter = DolarToOthers[3];
            break;
        }
        break;
    case 3:
        switch (c2)
        {
        case 0:
            converter = FuntToOthers[0];
            break;
        case 1:
            converter = FuntToOthers[1];
            break;
        case 2:
            converter = FuntToOthers[2];
            break;
        case 3:
            converter = FuntToOthers[3];
            break;
        }
        break;
    }

    return (a * converter);
}
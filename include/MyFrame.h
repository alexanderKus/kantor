#ifndef MYFRAME_H
#define MYFRAME_H

#include <wx/wx.h>
#include <vector>

class MyFrame: public wxFrame
{
public:
    // Konstruktor okna
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:

    // Menu bar functions
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    // Panele
    wxPanel *m_top_panel = nullptr;
    wxPanel *m_mid_panel = nullptr;
    wxPanel *m_bottom_panel = nullptr;

    // Box'y
    wxBoxSizer *m_box = nullptr;
    wxBoxSizer *m_top_box = nullptr;
    wxBoxSizer *m_mid_box = nullptr;
    wxBoxSizer *m_bottom_box = nullptr;

    // Pole textowe
    wxTextCtrl *m_txt1 = nullptr;

    // Zmienna przechowujaca kwote
    double amount;

    // Listowy wybor walut
    wxChoice *m_ch1 = nullptr;
    wxChoice *m_ch2 = nullptr;

    // Index'y walut z listy walut
    unsigned int m_ch1_index;
    unsigned int m_ch2_index;

    // Przycik do przeliczenia
    wxButton *m_btn1 = nullptr;

    // Lista walut
    wxArrayString currencies;

    // Vectory przechowujace wartosci przewalutowan
    std::vector<float> EurToOthers;
    std::vector<float> PlnToOthers;
    std::vector<float> DolarToOthers;
    std::vector<float> FuntToOthers;

    // Funkcja obslugujaca kliknieci przycisku
    void OnButtonClicked1(wxCommandEvent &event);

    // Funkcje obslugujace wybor walut
    void CurrencySelected1(wxCommandEvent &event);
    void CurrencySelected2(wxCommandEvent &event);

    // Funkcja do przeliczana walut
    float count(unsigned int c1, unsigned int c2, float a);

    wxDECLARE_EVENT_TABLE();
};

// Identyfikator opcji hello

// Identyfikator pola tekstowego
enum
{
    ID_TXT1 = 10
};

// Identyfikator przyciuku
enum
{
    ID_BTN1 = 100,
};

// Identyfikatory lisy walut
enum
{
    ID_Choice1 = 200,
    ID_Choice2 = 201,
};

#endif
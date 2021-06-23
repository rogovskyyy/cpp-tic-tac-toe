#include <iostream>
#include <vector>
#include <string>
#include <wx/log.h>
using namespace std;
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/msgdlg.h>

class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
};

class Game : public wxFrame
{
    public:
        Game(const wxString& title, const wxPoint& pos, const wxSize& size);
        int moves = 0;
        int board[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
        int cntr = 0;
        std::vector<wxWindow*> cntrls;
        void OnButton1_Click(wxCommandEvent& event);
        void OnButton2_Click(wxCommandEvent& event);
        void OnButton3_Click(wxCommandEvent& event);
        void OnButton4_Click(wxCommandEvent& event);
        void OnButton5_Click(wxCommandEvent& event);
        void OnButton6_Click(wxCommandEvent& event);
        void OnButton7_Click(wxCommandEvent& event);
        void OnButton8_Click(wxCommandEvent& event);
        void OnButton9_Click(wxCommandEvent& event);
        void UpdateElements();
        void isEnd();
        DECLARE_EVENT_TABLE()
};

enum
{
    BUTTON_1_PRESSED,
    BUTTON_2_PRESSED,
    BUTTON_3_PRESSED,
    BUTTON_4_PRESSED,
    BUTTON_5_PRESSED,
    BUTTON_6_PRESSED,
    BUTTON_7_PRESSED,
    BUTTON_8_PRESSED,
    BUTTON_9_PRESSED,
};

BEGIN_EVENT_TABLE(Game, wxFrame)
EVT_BUTTON(BUTTON_1_PRESSED, Game::OnButton1_Click)
EVT_BUTTON(BUTTON_2_PRESSED, Game::OnButton2_Click)
EVT_BUTTON(BUTTON_3_PRESSED, Game::OnButton3_Click)
EVT_BUTTON(BUTTON_4_PRESSED, Game::OnButton4_Click)
EVT_BUTTON(BUTTON_5_PRESSED, Game::OnButton5_Click)
EVT_BUTTON(BUTTON_6_PRESSED, Game::OnButton6_Click)
EVT_BUTTON(BUTTON_7_PRESSED, Game::OnButton7_Click)
EVT_BUTTON(BUTTON_8_PRESSED, Game::OnButton8_Click)
EVT_BUTTON(BUTTON_9_PRESSED, Game::OnButton9_Click)
END_EVENT_TABLE()
IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    wxLog* logger = new wxLogStream(&cout);
    wxLog::SetActiveTarget(logger);
    Game *gm = new Game("v1.0 Tic-Tac-Toe by Bartosz Rogowski", wxPoint(250, 250), wxSize(505, 525));
    gm->SetMinSize(wxSize(505, 525));
    gm->SetMaxSize(wxSize(505, 525));
    gm->Show(true);
    return true;
}

Game::Game(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
        wxPanel* pnl = new wxPanel(this, 0);
        wxFont myFont(18, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

        // czy 
        wxButton* btn1 = new wxButton(pnl, BUTTON_1_PRESSED, _T(""), wxPoint(10, 10), wxSize(150, 150), 0);
        // ==
        // wxButton* btn1(pnl, BUTTON_1_PRESSED, _T(""), wxPoint(10, 10), wxSize(150, 150), 0);
        wxButton* btn2 = new wxButton(pnl, BUTTON_2_PRESSED, _T(""), wxPoint(170, 10), wxSize(150, 150), 0);
        wxButton* btn3 = new wxButton(pnl, BUTTON_3_PRESSED, _T(""), wxPoint(330, 10), wxSize(150, 150), 0);
        wxButton* btn4 = new wxButton(pnl, BUTTON_4_PRESSED, _T(""), wxPoint(10, 170), wxSize(150, 150), 0);
        wxButton* btn5 = new wxButton(pnl, BUTTON_5_PRESSED, _T(""), wxPoint(170, 170), wxSize(150, 150), 0);
        wxButton* btn6 = new wxButton(pnl, BUTTON_6_PRESSED, _T(""), wxPoint(330, 170), wxSize(150, 150), 0);
        wxButton* btn7 = new wxButton(pnl, BUTTON_7_PRESSED, _T(""), wxPoint(10, 330), wxSize(150, 150), 0);
        wxButton* btn8 = new wxButton(pnl, BUTTON_8_PRESSED, _T(""), wxPoint(170, 330), wxSize(150, 150), 0);
        wxButton* btn9 = new wxButton(pnl, BUTTON_9_PRESSED, _T(""), wxPoint(330, 330), wxSize(150, 150), 0);

        btn1->SetFont(myFont);
        btn2->SetFont(myFont);
        btn3->SetFont(myFont);
        btn4->SetFont(myFont);
        btn5->SetFont(myFont);
        btn6->SetFont(myFont);
        btn7->SetFont(myFont);
        btn8->SetFont(myFont);
        btn9->SetFont(myFont);

        cntrls.push_back(btn1);
        cntrls.push_back(btn2);
        cntrls.push_back(btn3);
        cntrls.push_back(btn4);
        cntrls.push_back(btn5);
        cntrls.push_back(btn6);
        cntrls.push_back(btn7);
        cntrls.push_back(btn8);
        cntrls.push_back(btn9);
}

void Game::OnButton1_Click(wxCommandEvent& event) {
    if (this->board[0][0] == 0) {
        if (this->moves == 0) {
            this->board[0][0] = 1;
            this->moves = 1;
        }
        else {
            this->board[0][0] = 2;
            this->moves = 0;
        }
        cntr++;
    }
    Game::UpdateElements();
    Game::isEnd();
}

void Game::OnButton2_Click(wxCommandEvent& event) {
    if (this->board[0][1] == 0) {
        if (this->moves == 0) {
            this->board[0][1] = 1;
            this->moves = 1;
        }
        else {
            this->board[0][1] = 2;
            this->moves = 0;
        }
        cntr++;
    }
    Game::UpdateElements();
    Game::isEnd();
}

void Game::OnButton3_Click(wxCommandEvent& event) {
    if (this->board[0][2] == 0) {
        if (this->moves == 0) {
            this->board[0][2] = 1;
            this->moves = 1;
        }
        else {
            this->board[0][2] = 2;
            this->moves = 0;
        }

        cntr++;
    }
    Game::UpdateElements();
    Game::isEnd();
}

void Game::OnButton4_Click(wxCommandEvent& event) {
    if (this->board[1][0] == 0) {
        if (this->moves == 0) {
            this->board[1][0] = 1;
            this->moves = 1;
        }
        else {
            this->board[1][0] = 2;
            this->moves = 0;
        }
        cntr++;
    }
    Game::UpdateElements();
    Game::isEnd();
}

void Game::OnButton5_Click(wxCommandEvent& event) {
    if (this->board[1][1] == 0) {
        if (this->moves == 0) {
            this->board[1][1] = 1;
            this->moves = 1;
        }
        else {
            this->board[1][1] = 2;
            this->moves = 0;
        }
        cntr++;
    }
    Game::UpdateElements();
    Game::isEnd();
}

void Game::OnButton6_Click(wxCommandEvent& event) {
    if (this->board[1][2] == 0) {
        if (this->moves == 0) {
            this->board[1][2] = 1;
            this->moves = 1;
        }
        else {
            this->board[1][2] = 2;
            this->moves = 0;
        }
        cntr++;
    }
    Game::UpdateElements();
    Game::isEnd();
}

void Game::OnButton7_Click(wxCommandEvent& event) {
    if (this->board[2][0] == 0) {
        if (this->moves == 0) {
            this->board[2][0] = 1;
            this->moves = 1;
        }
        else {
            this->board[2][0] = 2;
            this->moves = 0;
        }
        cntr++;
    }
    Game::UpdateElements();
    Game::isEnd();
}

void Game::OnButton8_Click(wxCommandEvent& event) {
    if (this->board[2][1] == 0) {
        if (this->moves == 0) {
            this->board[2][1] = 1;
            this->moves = 1;
        }
        else {
            this->board[2][1] = 2;
            this->moves = 0;
        }
        cntr++;
    }
    Game::UpdateElements();
    Game::isEnd();
}

void Game::OnButton9_Click(wxCommandEvent& event) {
    if (this->board[2][2] == 0) {
        if (this->moves == 0) {
            this->board[2][2] = 1;
            this->moves = 1;
        }
        else {
            this->board[2][2] = 2;
            this->moves = 0;
        }
        cntr++;
    }
    Game::UpdateElements();
    Game::isEnd();
}

void Game::UpdateElements() {
    int iter = 0;
    for (int y = 0; y <= 2; y++) {
        for (int x = 0; x <= 2; x++) {
            if (this->board[y][x] == 0) {
                ((wxButton*)cntrls[iter])->SetLabel("");
            }
            else if (this->board[y][x] == 1) {
                ((wxButton*)cntrls[iter])->SetLabel("O");
            }
            else if (this->board[y][x] == 2) {
                ((wxButton*)cntrls[iter])->SetLabel("X");
            }
            iter++;
        }
    }
}

void Game::isEnd() {
    if (((this->board[0][0] == 1 && this->board[0][1] == 1 && this->board[0][2] == 1) ||
        (this->board[1][0] == 1 && this->board[1][1] == 1 && this->board[1][2] == 1) ||
        (this->board[2][0] == 1 && this->board[2][1] == 1 && this->board[2][2] == 1) ||
        (this->board[0][0] == 1 && this->board[1][0] == 1 && this->board[2][0] == 1) ||
        (this->board[0][1] == 1 && this->board[1][1] == 1 && this->board[2][1] == 1) ||
        (this->board[0][2] == 1 && this->board[1][2] == 1 && this->board[2][2] == 1) ||
        (this->board[0][0] == 1 && this->board[1][1] == 1 && this->board[2][2] == 1) ||
        (this->board[2][0] == 1 && this->board[1][1] == 1 && this->board[0][2] == 1)) && cntr <= 9)
    {
        wxMessageBox(wxT("Wygrał O"));
        Close(this);

    } else if 
        (((this->board[0][0] == 2 && this->board[0][1]  == 2 && this->board[0][2] == 2) ||
        (this->board[1][0]  == 2 && this->board[1][1]  == 2 && this->board[1][2] == 2) ||
        (this->board[2][0]  == 2 && this->board[2][1]  == 2 && this->board[2][2] == 2) ||
        (this->board[0][0]  == 2 && this->board[1][0]  == 2 && this->board[2][0] == 2) ||
        (this->board[0][1]  == 2 && this->board[1][1]  == 2 && this->board[2][1] == 2) ||
        (this->board[0][2]  == 2 && this->board[1][2]  == 2 && this->board[2][2] == 2) ||
        (this->board[0][0]  == 2 && this->board[1][1]  == 2 && this->board[2][2] == 2) ||
        (this->board[2][0]  == 2 && this->board[1][1]  == 2 && this->board[0][2] == 2)) && cntr <= 9) {
        wxMessageBox(wxT("Wygrał X"));
        Close(this);
    }
    else if(cntr == 9) {
        wxMessageBox(wxT("Remis"));
        Close(this);
    }

    //Close(this);
}
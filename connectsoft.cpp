#include <iostream>

#include "conexao.h"
#include "produtos.h"
#include "vendas.h"
#include "menu.h"
#include "funcionario.h"

using namespace std;

int main() {
	abrirMenu();
	
}

//#include <wx/wx.h>
//#include <libpq-fe.h>
//#include "conexao.h"
//#include "produtos.h"
//#include "vendas.h"
//
//// Função para criar a interface gráfica
//void CreateGui(PGconn* conn);
//
//class MyApp : public wxApp
//{
//public:
//    virtual bool OnInit();
//};
//
//class MyFrame : public wxFrame
//{
//public:
//    MyFrame(const wxString& title, PGconn* conn);
//
//private:
//    void OnAddProduct(wxCommandEvent& event);
//    void OnRegisterSale(wxCommandEvent& event);
//    void OnClose(wxCloseEvent& event);
//
//    wxTextCtrl* m_productNameCtrl;
//    wxTextCtrl* m_productValueCtrl;
//    wxTextCtrl* m_productQuantityCtrl;
//    wxTextCtrl* m_clientNameCtrl;
//    wxTextCtrl* m_saleTotalCtrl;
//    wxTextCtrl* m_saleQuantityCtrl;
//    wxTextCtrl* m_saleDescriptionCtrl;
//
//    PGconn* m_conn;
//};
//
//wxIMPLEMENT_APP(MyApp);
//
//bool MyApp::OnInit()
//{
//    const char* conninfo = "dbname=connectsoft user=postgres password=3016 hostaddr=127.0.0.1 port=5432";
//    PGconn* conn = conectarDB(conninfo);
//
//    if (conn == nullptr) {
//        wxLogError("Não foi possível conectar ao banco de dados.");
//        return false;
//    }
//
//    criarGUI(conn);
//     return true;
//}
//
//void criarGUI(PGconn* conn)
//{
//    MyFrame* frame = new MyFrame("Sistema de Vendas", conn);
//    frame->Show(true);
//}



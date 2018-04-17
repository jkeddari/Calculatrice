// On appelle le fichier de déclaration de notre classe
#include "myapp.hpp"

// La macro pour rediriger l'exécution vers notre classe
IMPLEMENT_APP(MyApp);

// L'implémentation de la méthode OnInit
bool MyApp::OnInit(){
	myWindow=new MainFrame( _T("Calculator"));

	// On fait en sorte que cet objet soit visible
	myWindow->Show();
	
	return true; //Pour que le programme ne se termine pas
}
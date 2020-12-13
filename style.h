using namespace std;

void out(string a){
	cout << a;
}

void nout(string a){
	cout << a << endl;
}

void tout(string a){
	cout <<"\t "<< a << endl;
}

void input(string a){
	cout << a;
}

void endln(int a){
	for(int i=0; i<a; i++){
		cout << endl;
	}
}

void line(){
	cout << "-------------------------------------------------------------------\n";
}

void gline(int a){
	for(int i=0; i<a; i++){
		input("-");
	}
	endln(1);
}

void tab(int a){
	for(int i=0; i<a; i++){
		cout << "\t";
	}
}
#include <iostream>

using namespace std;

char * toLowerCase( char *s){
	for (int i = 0; s[i] != '\0'; i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
	}
	return s;
}

char * toUpperCase( char *s){
	for (int i = 0; s[i] != '\0'; i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
	}
	return s;
}
int get_len(char *s){
	int i ;
	for (i = 0 ; s[i] != '\0' ;i++){}
	return i;
}

bool isValid(char s[]){
	for(int i = 0;s[i] != '\0';i++){
		if(!(s[i] >= 'a' && s[i] <= 'z')&&
		   !(s[i] >= 'A' && s[i] <= 'Z')&&
		   !(s[i] >= 48 && s[i] <= 57)){
			return 0;
		}
	}
	return 1;
}

char* reverse(char s[]){
	int i;
	for(i = 0 ; s[i] != '\0';i++){}
	char *sr = new char[i];
	i = i-1;
	int j;
	for(j = 0; i>= 0; i--,j++){
		sr[j] = s[i];
	}
	sr[j] = '\0';

	return sr;
}

char* reverse_v2(char s[]){
	int j;
	char t;
	for(j = 0 ; s[j] != '\0';j++){}
	j = j-1;
	int i;
	for(i = 0; i < j; i++,j--){
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
	//sr[j] = '\0';

	return s;
}

void compare(char A[] , char B[]){
	int i,j;
	for(i = 0,j = 0;A[i]!='\0' && B[j] != '\0';i++,j++){
		if(A[i]!= B[j])
			break;
	}
	if(A[i] == B[j])
		cout << "Equal"<<endl;
	else if(A[i] < B[j])
		cout << "First is smaller"<<endl;
	else
		cout << "First is larger"<<endl;
}


bool compareEgnoreCase(char A[],char B[]){
	// comparing 2 string ignoring the cases.
	
	A = toLowerCase(A);
	B = toLowerCase(B);
	int i,j;
	for(i = 0,j = 0;A[i]!='\0' && B[j] != '\0';i++,j++){
		if(A[i]!= B[j])
			break;
	}
	if(A[i] == B[j])
		return true;

	return false;
}

void find_duplicates_hashing(char s[]){
	int H[26] = {};
	int i;
	s = toLowerCase(s);
	for(i = 0; s[i] != '\0';i++){
		H[s[i]-97]++;
	}
	for(i = 0;i < 26;i++){
		if(H[i] > 1){
			printf("%c occurs %d times\n",i+97,H[i]);
		}
	}
}

void duplicacy_bits(char s[]){
	long int H = 0;
	long int X = 0;
	int i;
	for(i = 0; s[i] != '\0';i++){
		X = 1;
		X = X << (s[i] - 97);
		if((X & H) > 0){
			printf("%c is dupicate \n",s[i]);
		}else{
			H = X | H;
		}
	}
}

void is_anagram(char a[] ,char b[]){

	// function to check if 2 strings are anagram.
	// the hash table
	int H[26] = {0};

	int i;
	for(i = 0; a[i]!= '\0';i++){
		H[a[i] - 97]++;
	}

	// extra
	cout << endl;
	for (i = 0; i < 26; i++)
	{
		/* code */
		cout << H[i] << " ";
	}
	cout << endl;


	//
	for (i = 0; b[i]!= '\0'; i++)
	{
		H[b[i] - 97]--;
		if(H[b[i]-97] < 0){
			cout << "Not anagram"<<endl;
			break;
		}
	}
	if(b[i] == '\0')
		cout << "String is anagram"<<endl;

	cout << endl;
	for (int i = 0; i < 26; i++)
	{
		/* code */
		cout << H[i] << " ";
	}
	cout << endl;
}



void permutation(char s[],int k){
	static int A[10] = {0};
	static char R[10];


	int i;
	if(s[k] == '\0'){
		R[k] = '\0';
		cout << R <<endl;
	}
	else{
		for (i = 0; s[i] != '\0'; i++)
		{
			/* code */
			if(A[i] == 0){
				R[k] = s[i];
				A[i] = 1;
				permutation(s,k+1);
				A[i] = 0;
			}
		}
	}
}

char* swap(char s[],int a,int b){
	char temp = s[a];
	s[a] = s[b];
	s[b] = temp;
	return s;
}
void permutation_swap(char s[],int l,int h){
	int i;
	static int count = 0;

	// base case
	if(l == h){
		cout << s << endl;
		count ++;
		cout << count<<endl;
	}
	else{
		for(i = 0;i <= h;i++){
			s = swap(s,l,i);
			permutation_swap(s,l+1,h); // recursion
			s = swap(s,l,i); // backtracking
		}
	}
}

int main(int argc, char const *argv[])
{
	char name[] = "SOURABH";
	char city[] = "koderma";
	char country[] = "IndIA";
	/*
	cout << "length of "<<name<<" is "<<get_len(name)<<endl;
	cout << name << " == "<<toLowerCase(name)<<endl;
	cout << city << " == "<<toUpperCase(city)<<endl;
	cout << country << " == "<<toLowerCase(country)<<endl;

	//cout << isValid()<<endl;
	cout << "reverse of "<<name << " is "<<reverse_v2(name)<<endl;
	cout << "len of "<<name<<" is "<<get_len(name)<<" and len of "<<reverse(name)<<" is "<<get_len(reverse(name))<<endl;
	*/

	char A[] = "decimal";
	char B[] = "medical";
	//compare(A,B);
	//cout << toLowerCase(A)<<endl;
	//cout << compareEgnoreCase(A,B)<<endl;
	//char s[] = "finding";
	//find_duplicates_hashing(s);

	//duplicacy_bits(s);

	//is_anagram(A,B);

	char s[] = "DEF";
	//permutation(s,0);
	cout << "==="<<endl;
	//cout << swap(s,0,2) <<endl;
	permutation_swap(s,0,get_len(s)-1);
	return 0;
}
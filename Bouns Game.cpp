
#include <iostream>
using namespace std;


enum enLevel {Low =1 , Medum =2 , Hard =3 , Mixed = 4};
enum enOprator { Sum = 1, Subtract=2, Multiplication =3 , Divide =4 , mixed =5 };

struct stCustom {
	short Level;
	short Op ;


};
struct stQustion{
	short Number1;
	short Op;
	short Number2;


};

struct stAnswer {
	short RightAnswer = 0;
	short WrongAnser = 0;
	

};


short Random(short From, short To)
{
	short random = rand() % (To - From + 1) + From;
	return random;
}
short GetTheLevel(enLevel x)
{
	switch (x)
	{
	case Low:
		return Random(1, 9);
		break;
	case Medum:
		return Random(10, 50);

		break;
	case Hard:
		return Random(50, 100);

		break;
	case Mixed:
		GetTheLevel((enLevel)Random(1, 3));
		break;
	}
}
char GetTheOperator(enOprator x)
{
	switch (x)
	{
	case Sum:
		return '+';
		break;
	case Subtract:
		return '-';
		break;
	case Multiplication:
		return '*';
		break;
	case Divide:
		return '/';
		break;
	case mixed:
		GetTheOperator((enOprator)Random(1, 3));
		break;

	}
}


void checkAnswer(int number1,int number2,enOprator Op,int Answer , stAnswer & ckAnswer)
{
	
	int solution;
	switch (Op)
	{
	case Sum:
		solution = number1 + number2;
		if (Answer == solution){
			ckAnswer.RightAnswer++;
		cout << "\n Correct Answer :-) \n";
		}
		else
		{

			ckAnswer.WrongAnser++;
			cout << "\n False Answer :-( \n";

		}
		break;
	case Subtract:
		solution = number1 - number2;
		if (Answer == solution) {
			ckAnswer.RightAnswer++;
			cout << "\n Correct Answer :-) \n";
		}
		else
		{

			ckAnswer.WrongAnser++;
			cout << "\n False Answer :-( \n";

		}
		break;
	case Multiplication:
		solution = number1 * number2;
		if (Answer == solution) {
			ckAnswer.RightAnswer++;
			cout << "\n Correct Answer :-) \n";
		}
		else
		{

			ckAnswer.WrongAnser++;
			cout << "\n False Answer :-( \n";

		}
		break;
	case Divide:
		solution = number1 / number2;
		if (Answer == solution) {
			ckAnswer.RightAnswer++;
			cout << "\n Correct Answer :-) \n";
		}
		else
		{

			ckAnswer.WrongAnser++;
			cout << "\n False Answer :-( \n";

		}
		break;

	}
}
void qustion(short level , short op , stAnswer &ckAnswer)
{
	system("cls");
	int number1 = GetTheLevel((enLevel)level);
	int number2 = GetTheLevel((enLevel)level);
	char Op = GetTheOperator((enOprator)op);
	int Answer = 0;
	cout <<"\n"<< number1 << " " << Op << " " << number2 << " " << " = " << endl;
	cin >> Answer;
	checkAnswer(number1,number2,(enOprator)op,Answer, ckAnswer);
	




 }

short EnterLevel()
{
	short num;
	do
	{
		cout << "What do you want the level : \n [1]Low , [2]Medum , [3]Hard , [4]Mixes ?" << endl;
		cin >> num;

	} while (num<1 || num > 4);

	return num;
}


short EnterOperator()
{
	short num;
	do
	{
		cout << "What do you want the Operator : \n [1]Sum , [2]Subtract , [3]Multiplication , [4]Divide , [5]Mixed  ?" << endl;
		cin >> num;

	} while (num < 1 || num > 4);

	return num;
}




short numberOfRound()
{

	short num;

	do
	{

		cout << "Enter Number of rounds between [1 : 10]" << endl;
		cin >> num;


	} while (num < 1 || num > 10);

	return num;
}

void prinResult(stCustom custom ,stAnswer answer , short nfr)
{

	cout << "\n\n ---- \t Result \t ---- \n\n";
	cout << "The Number Of Rounds : " << nfr << endl;
	cout << "The Level : " << custom.Level << endl;
	cout << "The Operator : " << custom.Op << endl;
	cout << "The Right Answer : " << answer.RightAnswer << endl;
	cout << "The Wrong Answer : " << answer.WrongAnser<< endl;
}
void startGame()
{
	short numOfRound = numberOfRound();
	stCustom custom;
	custom.Level = EnterLevel();
	custom.Op = EnterOperator();
	stAnswer ckAnswer;
	for (short i = 0; i < numOfRound; i++)
	{
		qustion(custom.Level , custom.Op , ckAnswer);

	}

	prinResult(custom , ckAnswer , numOfRound);

}



int main()
{
	

	srand((unsigned) time(NULL));

	startGame();


}


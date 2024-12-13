#include <algorithm> // Untuk shuffle
#include <cstdlib>	 // Untuk system("pause")
#include <fstream>	 // Untuk membuka file
#include <iomanip>	 // Untuk memanipulasi output
#include <ios>		 // Untuk memanipulasi input
#include <iosfwd>	 // Untuk memanipulasi output
#include <iostream>	 // Untuk memanipulasi input dan output
#include <random>	 // Untuk shuffle
#include <sstream>	 // Untuk memanipulasi string
#include <string>	 // Untuk menggunakan tipe data string
#include <vector>	 // Untuk array dinamis

using namespace std; // Untuk meringkas std::

// Insialisasi fungsi
void signIn();
void signUp();
void mainMenu(string username);
void selectLevel(string username);
void selectRound(string username, int level);
void clue(string username, int level, int round);
void startGame(string username, int level, int round, int clue);
void updateScore(string username, int level, int points);
void leaderBoard(string username);
int getUserScore(string username, int level);
string shuffleWord(string word);

// Membuat struct
struct Auth
{
	string username;
	string password;
};

struct User
{
	string name;
	int easyLevelScore;
	int mediumLevelScore;
	int hardLevelScore;
};

struct LeaderBoard
{
	string easyLevelName;
	string mediumLevelName;
	string hardLevelName;
	string level;
	int easyLevelHighScore;
	int mediumLevelHighScore;
	int hardLevelHighScore;
};

int main()
{
	int menu;

	do
	{
		cout << "Menu\n";
		cout << "1. Login\n";
		cout << "2. Daftar\n";
		cout << "0. Exit\n";
		cout << "Pilih: ";
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
		case 1:
			signIn();
			system("pause");
			system("cls");
			break;
		case 2:
			signUp();
			system("pause");
			system("cls");
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia." << endl;
			system("pause");
			system("cls");
		}
	} while (menu != 0);

	return 0;
}

void signIn()
{
	Auth auth;
	User user;

	cout << "Masukkan Username : ";
	cin >> auth.username;

	cout << "Masukkan Password : ";
	cin >> auth.password;

	string fileName = auth.username + ".txt";
	ifstream file(fileName);

	if (file.is_open())
	{
		string line;
		string password;

		getline(file, line);
		getline(file, line);

		stringstream ss(line);
		ss >> user.name >> password; // Menangkap value dari file dan memasukannya ke variabel

		// Validasi password input dengan password file
		if (auth.password == password)
		{
			cout << "Login berhasil!" << endl;
			system("pause");
			system("cls");
			mainMenu(auth.username);
		}

		cout << "Username atau password salah!" << endl;

		file.close();
	}
	else
	{
		cout << "User tidak ditemukan!" << endl;
	}
}

void signUp()
{
	Auth auth;
	User user;

	cout << "Masukkan nama: ";
	cin >> user.name;

	cout << "Masukkan username: ";
	cin >> auth.username;

	cout << "Masukkan password: ";
	cin >> auth.password;

	string fileName = auth.username + ".txt";

	if (ifstream(fileName))
	{
		cout << "Username sudah terdaftar!" << endl;
		return;
	}

	ofstream file(fileName);

	if (file.is_open())
	{
		file << left << setw(20) << "Name"
			 << left << setw(20) << "Password"
			 << left << setw(20) << "Easy Level Score"
			 << left << setw(20) << "Medium Level Score"
			 << left << setw(20) << "Hard Level Score"
			 << endl;

		file << left << setw(20) << user.name
			 << left << setw(20) << auth.password
			 << left << setw(20) << 0
			 << left << setw(20) << 0
			 << left << setw(20) << 0
			 << endl;

		file.close();
		cout << "Pendaftaran berhasil!" << endl;
	}
	else
	{
		cout << "Pendaftaran gagal!" << endl;
	}
}

void mainMenu(string username)
{
	User user;
	string line;

	ifstream file(username + ".txt");

	getline(file, line);
	getline(file, line);

	stringstream ss(line);
	ss >> user.name;

	system("cls");

	cout << "Selamat datang, " << user.name << endl;

	int menu;
	do
	{
		cout << "Menu\n";
		cout << "1. Mulai bermain\n";
		cout << "2. Leaderboard\n";
		cout << "0. Kembali\n";
		cout << "Pilih: ";
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
		case 1:
			system("cls");
			selectLevel(username);
			break;
		case 2:
			system("cls");
			leaderBoard(username);
			break;
		case 0:
			system("cls");
			main();
			break;
		default:
			cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia." << endl;
			system("pause");
			system("cls");
		}
	} while (menu != 0);
}

void selectLevel(string username)
{
	int menu;

	do
	{
		cout << "Level\n";
		cout << "1. Easy\n";
		cout << "2. Medium\n";
		cout << "3. Hard\n";
		cout << "0. Kembali\n";
		cout << "Pilih: ";
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
		case 1:
			system("cls");
			selectRound(username, menu);
			break;
		case 2:
			system("cls");
			selectRound(username, menu);
			break;
		case 3:
			system("cls");
			selectRound(username, menu);
			break;
		case 0:
			system("cls");
			mainMenu(username);
			break;
		default:
			cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia." << endl;
			system("pause");
			system("cls");
		}
	} while (menu != 0);
}

void selectRound(string username, int level)
{
	int menu;

	do
	{
		cout << "Round\n";
		cout << "1. 1 Round\n";
		cout << "2. 3 Round\n";
		cout << "3. 5 Round\n";
		cout << "0. Kembali\n";
		cout << "Pilih: ";
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
		case 1:
			system("cls");
			clue(username, level, menu);
			break;
		case 2:
			system("cls");
			clue(username, level, menu);
			break;
		case 3:
			system("cls");
			clue(username, level, menu);
			break;
		case 0:
			system("cls");
			selectLevel(username);
			break;
		default:
			cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia." << endl;
			system("pause");
			system("cls");
		}
	} while (menu != 0);
}

void clue(string username, int level, int round)
{
	int menu;

	do
	{
		cout << "Clue\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "0. Kembali\n";
		cout << "Pilih: ";
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
		case 1:
			startGame(username, level, round, menu);
			system("pause");
			system("cls");
			break;
		case 2:
			startGame(username, level, round, menu);
			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");
			selectRound(username, level);
			break;
		default:
			cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia." << endl;
			system("pause");
			system("cls");
		}
	} while (menu != 0);
}

void startGame(string username, int level, int round, int clue)
{
	vector<string> easyWords = {"Buku", "Amplop", "Karet", "Gitar", "Gayung"};
	vector<string> easyQuestions = {"Suka diliatin.", "Kalo dikasih pasti seneng.", "Ditarik makin panjang.", "Suka dipetik orang.", "Suka buang buang air."};
	vector<string> mediumWords = {"Akuarium", "Banteng", "Sepatu", "Gendang", "Almarhum"};
	vector<string> mediumQuestions = {"Tempat tinggal hewan air.", "Presiden ke 5 Indonesia.", "Bau sikil.", "Suka dipukul tapi ga marah.", "Gelar yang bikin keluarga nangis."};
	vector<string> hardWords = {"Perangkap", "Kakaktua", "Layangan", "Kelelawar", "Kalimantan"};
	vector<string> hardQuestions = {"Dipakai untuk menjebak target buruan.", "Hewan yang tidak pernah muda.", "Bisa terbang sangat tinggi.", "Hewan yang siang tidur, malam cari nafkah.", "Kali yang besar dan banyak penghuninya."};

	int roundCount;
	bool isClue;
	vector<string> words;
	vector<string> questions;

	// Set level
	if (level == 1)
	{
		words = easyWords;
		questions = easyQuestions;
	}
	else if (level == 2)
	{
		words = mediumWords;
		questions = mediumQuestions;
	}
	else if (level == 3)
	{
		words = hardWords;
		questions = hardQuestions;
	}

	// Set round
	if (round == 1)
	{
		roundCount = 1;
	}
	else if (round == 2)
	{
		roundCount = 3;
	}
	else if (round == 3)
	{
		roundCount = 5;
	}

	// Set clue
	if (clue == 1)
	{
		isClue = true;
	}
	else if (clue == 2)
	{
		isClue = false;
	}

	system("cls");

	vector<string> selectedWords;
	vector<string> selectedQuestions;

	// Mengacak urutan array
	vector<int> indices = {0, 1, 2, 3, 4};
	shuffle(indices.begin(), indices.end(), random_device());

	for (int i = 0; i < indices.size(); i++)
	{
		selectedWords.push_back(words[indices[i]]);
		selectedQuestions.push_back(questions[indices[i]]);
	}

	string guess;
	int maxGuesses = 3;
	int attempts = 0;
	int points = 0;

	for (int i = 0; i < roundCount; i++)
	{
		string originalWord = selectedWords[i];
		string shuffledWord = shuffleWord(originalWord);

		attempts = 0;
		while (guess != originalWord && attempts < maxGuesses)
		{
			cout << endl;
			cout << "Highscore anda di level ini: " << getUserScore(username, level) << endl;
			cout << "Point anda: " << points << endl;

			cout << endl;

			if (isClue == true)
			{
				cout << "Question: " << selectedQuestions[i] << endl;
			}

			cout << "Guess the word: " << shuffledWord << endl;
			cout << endl;
			cout << "Masukkan tebakan Anda: ";
			getline(cin, guess);

			if (guess == originalWord)
			{
				system("cls");
				cout << "Tebakan Anda benar!" << endl;

				points = points + 10;

				break;
			}
			else
			{
				system("cls");

				cout << "Tebakan Anda salah!" << endl;
				attempts++;

				if (attempts < maxGuesses)
				{
					cout << "Tersisa " << (maxGuesses - attempts) << " tebakan." << endl;
				}
				else
				{
					system("cls");
					cout << "Skor Anda: " << points << endl;
					cout << "Permainan berakhir. Kata yang benar adalah: " << originalWord << endl;
					system("pause");
					updateScore(username, level, points);
					mainMenu(username);
				}
			}
		}
	}

	system("cls");
	cout << "Skor Anda: " << points << endl;
	updateScore(username, level, points);
	system("pause");
	mainMenu(username);
}

void updateScore(string username, int level, int points)
{
	Auth auth;
	User user;
	LeaderBoard leaderBoard;
	string line, header, easy, medium, hard;

	ifstream getData(username + ".txt");
	getline(getData, line);
	getline(getData, line);

	stringstream ss(line);
	ss >> user.name >> auth.password >> user.easyLevelScore >> user.mediumLevelScore >> user.hardLevelScore;

	ofstream updateData(username + ".txt");
	if (updateData.is_open())
	{
		updateData << left << setw(20) << "Name"
				   << left << setw(20) << "Password"
				   << left << setw(20) << "Easy Level Score"
				   << left << setw(20) << "Medium Level Score"
				   << left << setw(20) << "Hard Level Score"
				   << endl;

		updateData << left << setw(20) << user.name
				   << left << setw(20) << auth.password
				   << left << setw(20) << (level == 1 && points > user.easyLevelScore ? points : user.easyLevelScore)
				   << left << setw(20) << (level == 2 && points > user.mediumLevelScore ? points : user.mediumLevelScore)
				   << left << setw(20) << (level == 3 && points > user.hardLevelScore ? points : user.hardLevelScore)
				   << endl;

		updateData.close();
	}
	else
	{
		cout << "Gagal membuka file." << endl;
	}

	ifstream getLeaderBoardData("leaderboard.txt");
	getline(getLeaderBoardData, header);
	getline(getLeaderBoardData, easy);
	getline(getLeaderBoardData, medium);
	getline(getLeaderBoardData, hard);

	stringstream ssEasy(easy);
	ssEasy >> leaderBoard.level >> leaderBoard.easyLevelName >> leaderBoard.easyLevelHighScore;

	stringstream ssMedium(medium);
	ssMedium >> leaderBoard.level >> leaderBoard.mediumLevelName >> leaderBoard.mediumLevelHighScore;

	stringstream ssHard(hard);
	ssHard >> leaderBoard.level >> leaderBoard.hardLevelName >> leaderBoard.hardLevelHighScore;

	if (!getLeaderBoardData.is_open())
	{
		leaderBoard.easyLevelName = "N/A";
		leaderBoard.mediumLevelName = "N/A";
		leaderBoard.hardLevelName = "N/A";
		leaderBoard.easyLevelHighScore = 0;
		leaderBoard.mediumLevelHighScore = 0;
		leaderBoard.hardLevelHighScore = 0;
	}

	if (level == 1 && points >= leaderBoard.easyLevelHighScore)
	{
		leaderBoard.easyLevelName = user.name;
		leaderBoard.easyLevelHighScore = points;
	}
	else if (level == 2 && points >= leaderBoard.mediumLevelHighScore)
	{
		leaderBoard.mediumLevelName = user.name;
		leaderBoard.mediumLevelHighScore = points;
	}
	else if (level == 3 && points >= leaderBoard.hardLevelHighScore)
	{
		leaderBoard.hardLevelName = user.name;
		leaderBoard.hardLevelHighScore = points;
	}

	ofstream updateLeaderBoardData("leaderboard.txt");
	if (updateLeaderBoardData.is_open())
	{
		updateLeaderBoardData << left << setw(20) << "Level" << left << setw(20) << "Name" << left << setw(20) << "Score" << endl;
		updateLeaderBoardData << left << setw(20) << "Easy" << left << setw(20) << leaderBoard.easyLevelName << left << setw(20) << (leaderBoard.easyLevelHighScore ? leaderBoard.easyLevelHighScore : 0) << endl;
		updateLeaderBoardData << left << setw(20) << "Medium" << left << setw(20) << leaderBoard.mediumLevelName << left << setw(20) << (leaderBoard.mediumLevelHighScore ? leaderBoard.mediumLevelHighScore : 0) << endl;
		updateLeaderBoardData << left << setw(20) << "Hard" << left << setw(20) << leaderBoard.hardLevelName << left << setw(20) << (leaderBoard.hardLevelHighScore ? leaderBoard.hardLevelHighScore : 0) << endl;
		updateLeaderBoardData.close();
	}
	else
	{
		cout << "Gagal membuka file." << endl;
	}
}

void leaderBoard(string username)
{
	Auth auth;
	User user;
	LeaderBoard leaderBoard;

	string header, data, easy, medium, hard;

	ifstream getLeaderBoardData("leaderboard.txt");

	if (!getLeaderBoardData.is_open())
	{
		leaderBoard.easyLevelName = "N/A";
		leaderBoard.mediumLevelName = "N/A";
		leaderBoard.hardLevelName = "N/A";
		leaderBoard.easyLevelHighScore = 0;
		leaderBoard.mediumLevelHighScore = 0;
		leaderBoard.hardLevelHighScore = 0;
	}

	getline(getLeaderBoardData, header);
	getline(getLeaderBoardData, easy);
	getline(getLeaderBoardData, medium);
	getline(getLeaderBoardData, hard);

	stringstream ssEasy(easy);
	ssEasy >> leaderBoard.level >> leaderBoard.easyLevelName >> leaderBoard.easyLevelHighScore;

	stringstream ssMedium(medium);
	ssMedium >> leaderBoard.level >> leaderBoard.mediumLevelName >> leaderBoard.mediumLevelHighScore;

	stringstream ssHard(hard);
	ssHard >> leaderBoard.level >> leaderBoard.hardLevelName >> leaderBoard.hardLevelHighScore;

	cout << "+------------------------------------------------------------+" << endl;
	cout << "|                        Leaderboard                         |" << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|" << left << setw(20) << "Level" << left << setw(20) << "Name" << left << setw(20) << "Score" << "|" << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|" << left << setw(20) << "Easy" << left << setw(20) << leaderBoard.easyLevelName << left << setw(20) << leaderBoard.easyLevelHighScore << "|" << endl;
	cout << "|" << left << setw(20) << "Medium" << left << setw(20) << leaderBoard.mediumLevelName << left << setw(20) << leaderBoard.mediumLevelHighScore << "|" << endl;
	cout << "|" << left << setw(20) << "Hard" << left << setw(20) << leaderBoard.hardLevelName << left << setw(20) << leaderBoard.hardLevelHighScore << "|" << endl;
	cout << "+------------------------------------------------------------+" << endl;

	cout << endl;

	ifstream getUserData(username + ".txt");

	getline(getUserData, header);
	getline(getUserData, data);

	stringstream ss(data);
	ss >> user.name >> auth.password >> user.easyLevelScore >> user.mediumLevelScore >> user.hardLevelScore;

	cout << "+--------------------------------------------------------------------------------+" << endl;
	cout << "|                                     User                                       |" << endl;
	cout << "+--------------------------------------------------------------------------------+" << endl;
	cout << "|" << left << setw(20) << "Name" << left << setw(20) << "Easy Level Score" << left << setw(20) << "Medium Level Score" << left << setw(20) << "Hard Level Score" << "|" << endl;
	cout << "+--------------------------------------------------------------------------------+" << endl;
	cout << "|" << left << setw(20) << user.name << left << setw(20) << user.easyLevelScore << left << setw(20) << user.mediumLevelScore << left << setw(20) << user.hardLevelScore << "|" << endl;
	cout << "+--------------------------------------------------------------------------------+" << endl;

	cout << endl;

	system("pause");
	system("cls");
}

int getUserScore(string username, int level)
{
	Auth auth;
	User user;
	string line;

	ifstream getData(username + ".txt");
	getline(getData, line);
	getline(getData, line);

	stringstream ss(line);
	ss >> user.name >> auth.password >> user.easyLevelScore >> user.mediumLevelScore >> user.hardLevelScore;

	int showScore = level == 1 ? user.easyLevelScore : level == 2 ? user.mediumLevelScore
																  : user.hardLevelScore;

	return showScore;
}

string shuffleWord(string word)
{
	shuffle(word.begin(), word.end(), random_device());
	return word;
}
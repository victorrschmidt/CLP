#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

string trim(const string& str) {
    const string whitespace = " \t\n\r";
    size_t start = str.find_first_not_of(whitespace);
    if (start == string::npos) {
        return "";
    }
    size_t end = str.find_last_not_of(whitespace);
    return str.substr(start, end - start + 1);
}

class FileAnalyzer {
private:
    ifstream reader;
    string filePath;

    void showFileInfo(int lineCount, int wordCount, int charCount) const {
        cout << "Nome do arquivo: " << filePath << '\n';
        cout << "Num de linhas: " << lineCount << '\n';
        cout << "Num de palavras: " << wordCount << '\n';
        cout << "Num de caracteres: " << charCount << "\n\n";
    }

public:
    explicit FileAnalyzer(const string& filePath)
        : reader("texts/" + filePath), filePath(filePath)
    {
        if (!reader.is_open()) {
            throw runtime_error(filePath);
        }
    }

    void analyzeContent() {
        int lineCount = 0;
        int wordCount = 0;
        int charCount = 0;
        string line;
        while (getline(reader, line)) {
            if (line.find("#ERRO#") != string::npos) {
                showFileInfo(lineCount, wordCount, charCount);
                throw invalid_argument("");
            }
            istringstream stream(line);
            string word;
            while (stream >> word) {
                wordCount++;
            }
            lineCount += 1;
            charCount += trim(line).length();
        }
        if (reader.bad()) {
            throw ios_base::failure("Erro durante a leitura do arquivo: " + filePath);
        }
        showFileInfo(lineCount, wordCount, charCount);
    }
};

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        try {
            FileAnalyzer fa(argv[i]);
            fa.analyzeContent();
        }
        catch (const runtime_error& e) {
            cerr << "ERRO. Arquivo nao encontrado.\n" << e.what() << "\n\n";
        }
        catch (const invalid_argument& e) {
            cerr << "Processamento interrompido por encontrar a string #ERRO#.\n\n";
        }
        catch (const exception& e) {
            cerr << "ERRO. Problema de leitura do arquivo.\n" << e.what() << "\n\n";
        }
    }

    return 0;
}

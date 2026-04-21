#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_valid_message(const string &text) {
    for (char c : text) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
            return false;
        }
    }
    return true;
}

string rail_fence_encrypt(const string &plaintext, int rails) {
    if (rails <= 1 || plaintext.empty()) return plaintext;

    vector<string> fence(rails, "");
    int rail = 0;
    int direction = 1;

    for (char c : plaintext) {
        // Q6: giữ nguyên dấu cách
        fence[rail] += c;
        rail += direction;
        if (rail == rails - 1 || rail == 0) direction = -direction;
    }

    string ciphertext;
    for (const string &row : fence) ciphertext += row;
    return ciphertext;
}

string rail_fence_decrypt(const string &ciphertext, int rails) {
    if (rails <= 1 || ciphertext.empty()) return ciphertext;

    int n = ciphertext.length();
    vector<vector<char>> fence(rails, vector<char>(n, '\n'));

    // Bước 1: đánh dấu zig-zag
    int row = 0, direction = 1;
    for (int col = 0; col < n; col++) {
        fence[row][col] = '*';
        row += direction;
        if (row == rails - 1 || row == 0) direction = -direction;
    }

    // Bước 2: điền ciphertext vào
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < n; j++) {
            if (fence[i][j] == '*' && index < n) {
                fence[i][j] = ciphertext[index++];
            }
        }
    }

    // Bước 3: đọc lại zig-zag
    string plaintext;
    row = 0;
    direction = 1;
    for (int col = 0; col < n; col++) {
        plaintext += fence[row][col];
        row += direction;
        if (row == rails - 1 || row == 0) direction = -direction;
    }

    return plaintext;
}

// Q7: ghi file
void write_message_to_file(const string &path, const string &message) {
    ofstream fout(path);
    fout << message;
}

// đọc file (1 dòng)
string read_message_from_file(const string &path) {
    ifstream fin(path);
    string line;
    getline(fin, line);
    return line;
}

// Q8: đọc full file
string read_full_message_from_file(const string &path) {
    ifstream fin(path);
    string line, result;
    while (getline(fin, line)) {
        result += line;
    }
    return result;
}

int main() {
    cout << "=== Rail Fence Cipher Demo ===\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "3. Read from file and encrypt\n";
    cout << "4. Encrypt and save to file\n";   // Q7
    cout << "5. Read from file and decrypt\n"; // Q8
    cout << "Choose: ";

    int choice;
    cin >> choice;
    cin.ignore();

    string message;
    int rails;

    if (choice == 3) {
        message = read_message_from_file("data/input.txt");
        cout << "Message from file: " << message << "\n";

        cout << "Enter rails: ";
        cin >> rails;

        if (!is_valid_message(message)) {
            cout << "Invalid input.\n";
            return 0;
        }

        cout << "Ciphertext: " << rail_fence_encrypt(message, rails) << "\n";
    }

    else if (choice == 4) { // Q7
        cout << "Enter message: ";
        getline(cin, message);

        cout << "Enter rails: ";
        cin >> rails;

        if (!is_valid_message(message)) {
            cout << "Invalid input.\n";
            return 0;
        }

        string cipher = rail_fence_encrypt(message, rails);
        write_message_to_file("data/output.txt", cipher);

        cout << "Saved ciphertext to file: " << cipher << "\n";
    }

    else if (choice == 5) { // Q8
        string cipher = read_full_message_from_file("data/output.txt");

        cout << "Ciphertext from file: " << cipher << "\n";

        cout << "Enter rails: ";
        cin >> rails;

        cout << "Plaintext: " << rail_fence_decrypt(cipher, rails) << "\n";
    }

    else {
        cout << "Enter message: ";
        getline(cin, message);

        cout << "Enter rails: ";
        cin >> rails;

        if (!is_valid_message(message)) {
            cout << "Invalid input.\n";
            return 0;
        }

        if (choice == 1) {
            cout << "Ciphertext: " << rail_fence_encrypt(message, rails) << "\n";
        } else if (choice == 2) {
            cout << "Plaintext: " << rail_fence_decrypt(message, rails) << "\n";
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

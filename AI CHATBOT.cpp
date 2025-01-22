#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string toLowerCase(const string& input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string analyzeSentiment(const string& message) {
    if (message.find("happy") != string::npos || message.find("good") != string::npos || message.find("great") != string::npos) {
        return "positive";
    }
    if (message.find("sad") != string::npos || message.find("bad") != string::npos || message.find("angry") != string::npos) {
        return "negative";
    }
    return "neutral";
}

string tellJoke() {
    vector<string> jokes = {
        "Why don't scientists trust atoms? Because they make up everything!",
        "Why did the computer go to the doctor? Because it caught a virus!",
        "What do you call fake spaghetti? An impasta!",
        "Why did the bicycle fall over? Because it was two-tired!",
        "What do you call cheese that isn't yours? Nacho cheese!"
    };

    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % jokes.size();
    return jokes[randomIndex];
}

string getResponse(const string& userMessage) {
    map<string, string> responses = {
        {"hello", "Hello! Nice to meet you. How can I assist you today?"},
        {"how are you", "I am just a AI Chatbot, but I am doing well! How about you?"},
        {"what is your name", "I am your assistant. You can call me BUBBLE."},
        {"what can you do", "I can chat with you, answer simple questions, analyze your mood, and tell jokes!"},
        {"tell me a joke", tellJoke()},
        {"bye", "Goodbye! Take care and have a wonderful day!"}
    };

    string lowerMessage = toLowerCase(userMessage);

    if (responses.find(lowerMessage) != responses.end()) {
        return responses[lowerMessage];
    }

    return "I am not sure how to respond to that. Can you ask me something else?";
}

int main() {
    cout << "BUBBLE: Hi! I am here to chat with you. Type 'bye' to end the conversation." << endl;

    while (true) {
        cout << "You: ";
        string userInput;
        getline(cin, userInput);

        if (toLowerCase(userInput) == "bye") {
            cout << "BUBBLE: Take care! It was great chatting with you" << endl;
            break;
        }

        string sentiment = analyzeSentiment(toLowerCase(userInput));

        if (sentiment == "positive") {
            cout << "BUBBLE: I am glad to hear that! Tell me more!" << endl;
        } else if (sentiment == "negative") {
            cout << "BUBBLE: I am sorry to hear that. Is there anything I can do to help?" << endl;
        } else {
            cout << "BUBBLE: " << getResponse(userInput) << endl;
        }
    }

    return 0;
}
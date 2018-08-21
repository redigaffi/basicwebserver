//
// Created by Jordi Walter Hoock on 18/08/2018.
//

#include <iostream>
#include "RequestParser.h"


void RequestParser::parseRequest(const char request[], int size) {

    ::std::vector <::std::string> requestParsed(20);
    ::std::string buffer;

    for (int i = 0, a = 0; i < size; i++ ) {

        char  letter = request[i];

        if (letter == '\0') {
            break;
        }

        buffer += letter;

        if (letter == '\n') {
            requestParsed[a] = buffer;
            a++;
            buffer = "";
        }

    }

}

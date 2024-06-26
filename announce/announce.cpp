//
// SA:MP Multiplayer Modification For GTA:SA
// Copyright 2004-2005 SA:MP team
// Copyright 2022-2024 RedLightTeam
// Version: $Id: announce.cpp, v 1.5 2024/06/26 20:35 kyeman Exp $
//
//----------------------------------------------------------

#include <iostream>
#include <memory>
#include <string>

#ifdef WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

#include "httpclient.h"

#ifdef WIN32

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    std::string cmdLine(lpszCmdLine);
    if(cmdLine.empty() || cmdLine.length() > 5) return 0;

    std::unique_ptr<CHttpClient> pHttpClient(new CHttpClient());

    std::string szURL = "server.sa-mp.com/0.2.X/announce/" + cmdLine;

    pHttpClient->ProcessURL(HTTP_GET, szURL.c_str(), nullptr, "Bonus");

    return 0;
}

#else

int main(int argc, char *argv[])
{
    if(argc != 2 || std::strlen(argv[1]) > 5) return 0;

    std::unique_ptr<CHttpClient> pHttpClient(new CHttpClient());

    std::string szURL = "server.sa-mp.com/0.2.X/announce/" + std::string(argv[1]);

    pHttpClient->ProcessURL(HTTP_GET, szURL.c_str(), nullptr, "Bonus");

    return 0;
}

#endif

//****************************************************************************
// File name:	 SDLApp.h
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS 485
// Assignment: 01_Assignment_Shapes
// Purpose:    Provide a wrapper around SDL and a simple game loop
//****************************************************************************
#pragma once
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "SDL_ttf.h"			// true type font
#include <string>
#include <vector>
#include "Color.h"
#include <map>
#include "ISDLWidgetTextable.h"
#include "ISDLWidgetClickable.h"

class SDLTextWidget;
class SDLSprite;

class SDLApp
{
public:
  SDLApp (unsigned int framesPerSecond = 60);
  SDLApp (const SDLApp&) = delete;

  virtual ~SDLApp ();

  SDLApp& operator=(const SDLApp&) = delete;

  bool createWindow (std::string windowName,
    int windowXPos = 100,
    int windowYPos = 100,
    int windowSizeX = 640,
    int windowSizeY = 640);
  void setWindowBackgroundColor (Color cRgba);

  void cleanup ();

  void setColor (Color cRgba);
  Color getColor () const;
  void drawLine (int x1, int y1, int x2, int y2);
  void drawCircle (int x, int y, int radius);
  void drawBox (int x, int y, int x2, int y2);

  void displayText (int x, int y, std::string msg, Color cRgba);

  int loadFont (std::string fontname, int size);
  bool displayText (int x, int y, std::string msg, Color cRgba, int font);
  bool displayTextClickable (int x, int y, std::string msg, Color cRgba, 
    int font, int &rW, int &rH);

  bool loadSprite (std::string name, int &w, int &h);
  void displaySprite (const SDLSprite &rcSprite);

  void gameLoop ();
  unsigned int getFramesPerSecond ();


  void enableTextInput ();
  void disableTextInput ();

  void registerTextWidget (ISDLWidgetTextable *pcWidget);
  void registerClickableWidget (ISDLWidgetClickable *pcClickable);

  // subclasses should implement each of the
  // following methods as necessary to customize
  // their App.
  virtual void initGame ();
  virtual void update ();
  virtual void handleEvent (SDL_Event event);

  virtual void render () = 0;

private:

  SDL_Window *mpWindow = nullptr;
  SDL_Renderer *mpRenderer = nullptr;

  // current color
  Color mcCurrentColor;

  // background color
  Color mcBackgroundColor;

  std::vector<TTF_Font *> mcFonts;

  std::vector<ISDLWidgetClickable *> mcClickWidgetVector;
  std::vector<ISDLWidgetTextable *> mcTextWidgetVector;
  ISDLWidgetTextable *mpFocusTextWidget = nullptr;

  bool mbTextInputActive = false;
  bool mbEnableTextInput = false;

  std::map<std::string, SDL_Texture*> mcSpriteMap;
  void handleTextEvent (SDL_Event event);

  unsigned int mFramesPerSecond;
};
//****************************************************************************
// File name:	 SDLApp.cpp
// Author:     Chadd Williams
// Date:       3/30/2017
// Class:      CS 485
// Assignment: SDLApp2
// Purpose:    Provide a wrapper around SDL and a simple game loop
//****************************************************************************
#include "SDLApp.h"
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include <iostream>
#include "SDL_ttf.h"			// true type font
#include "SDLTextWidget.h"
#include "SDLSprite.h"
#include "SDL_image.h"
#include <algorithm>

//***************************************************************************
// Constructor: SDLApp
//
// Description: Initialize background, current color, and the font system.
//
// Parameters:  unsigned int - frames per second (default 60)
//
// Returned:    None
//***************************************************************************
SDLApp::SDLApp (unsigned int framesPerSecond) : 
  mFramesPerSecond(framesPerSecond),
  mcBackgroundColor (255, 255, 255, 255),
  mcCurrentColor (0, 0, 0, 0)
{
  TTF_Init ();
}

//***************************************************************************
// Function:    createWindow
//
// Description: Create a window using the given specifications
//              Initialize SDL, Create a Window, and Create Renderer
//
// Parameters:  windowName - name in the window's title bar
//              windowXPos - initial x position of the window on the screen
//              windowYPos - initial y position of the window on the screen
//              windowSizeX - initial x size of the window on the screen
//              windowSizeY - initial y size of the window on the screen
//
// Returned:    true or false to indicate success
//***************************************************************************
bool SDLApp::createWindow (std::string windowName, int windowXPos,
  int windowYPos,
  int windowSizeX,
  int windowSizeY)
{
  if (SDL_Init (SDL_INIT_EVERYTHING) == -1)
  {
    std::cout << " Failed to initialize SDL : " << 
      SDL_GetError () << std::endl;
    return false;
  }

  mpWindow = SDL_CreateWindow (windowName.c_str (), windowXPos, windowYPos,
    windowSizeX, windowSizeY, 0);

  if (nullptr == mpWindow)
  {
    std::cout << "Failed to create window : " << SDL_GetError ();
    return false;
  }

  mpRenderer = SDL_CreateRenderer (mpWindow, -1, 0);

  if (nullptr == mpRenderer)
  {
    std::cout << "Failed to create renderer : " << SDL_GetError ();
    return false;
  }

  // Set size of renderer to the same as window
  SDL_RenderSetLogicalSize (mpRenderer, windowSizeX, windowSizeY);
  return true;
}

//***************************************************************************
// Function:    setColor
//
// Description: set the current drawing color
//
// Parameters:  rgba - the color to use
//
// Returned:    None
//***************************************************************************
void SDLApp::setColor (Color cRgba)
{
  mcCurrentColor = cRgba;
}

//***************************************************************************
// Function:    getColor
//
// Description: get the current drawing color
//
// Parameters:  None
//
// Returned:    the current color
//***************************************************************************
Color SDLApp::getColor () const
{
  return mcCurrentColor;
}

//***************************************************************************
// Function:    drawLine
//
// Description: draw a line between the given points using the drawing color
//
// Parameters:  x1 - x position of point 1
//              y1 - y position of point 2
//              x2 - x position of point 1
//              y1 - y position of point 2
//
// Returned:    None
//***************************************************************************
void SDLApp::drawLine (int x1, int y1, int x2, int y2)
{
  lineRGBA (mpRenderer, x1, y1, x2, y2,
    mcCurrentColor.getR (),
    mcCurrentColor.getG (),
    mcCurrentColor.getB (),
    mcCurrentColor.getA ());
}

//***************************************************************************
// Function:    drawCircle
//
// Description: draw a circle at the given point of the given radius.  The 
//              circle is filled with the current draw color.
//
// Parameters:  x - x center of the circle
//              y - y center of the circle
//              radius - radius of the circle
//
// Returned:    None
//***************************************************************************
void SDLApp::drawCircle (int x, int y, int radius)
{
  //draw circle
  filledCircleRGBA (mpRenderer, x, y, radius,
    mcCurrentColor.getR (),
    mcCurrentColor.getG (),
    mcCurrentColor.getB (),
    mcCurrentColor.getA ());

}

//***************************************************************************
// Function:    drawBox
//
// Description: draw a box between the give points (x1,y1), (x2,y2)
//              The box is filled with the current draw color.
//
// Parameters:  x1 - x top left
//              y1 - y top left
//              x2 - x bottom right
//              y2 - y bottom right
//
// Returned:    None
//***************************************************************************
void SDLApp::drawBox (int x1, int y1, int x2, int y2)
{
  boxRGBA (mpRenderer, x1, y1, x2, y2, mcCurrentColor.getR (),
    mcCurrentColor.getG (),
    mcCurrentColor.getB (),
    mcCurrentColor.getA ());
}

//***************************************************************************
// Function:    loadFont
//
// Description: Load the given font using the given size.
//
// Parameters:  fontname - full path to the font file
//              size - size of the font
//
// Returned:    int - the id of the font or -1 on error
//***************************************************************************
int SDLApp::loadFont (std::string fontname, int size)
{
  TTF_Font *pFont = TTF_OpenFont (fontname.c_str (), size);
  int retVal = -1;

  if (nullptr != pFont)
  {
    mcFonts.push_back (pFont);
    retVal = mcFonts.size ();
  }

  return retVal;
}

//***************************************************************************
// Function:    displayText
//
// Description: Display text on the screen at the given location.  
//
// Parameters:  x - x position
//              y - y position
//              msg - the text to display
//              rgba - the color of the text
//              font - the font id returned by loadFont
//
// Returned:    true or false to indicate success
//***************************************************************************
bool SDLApp::displayText (int x, int y, std::string msg, Color cRgba, int font)
{
  SDL_Color color = { cRgba.getR (), cRgba.getG (), 
    cRgba.getB (), cRgba.getA () };
  SDL_Surface *pSurface = TTF_RenderText_Blended (mcFonts.at (font - 1),
    msg.c_str (), color);
  if (nullptr == pSurface)
  {
    //std::cout << "Failed to create surface : " << SDL_GetError();
    return false;
  }

  // Map the Surface onto a Texture
  SDL_Texture *pTexture = SDL_CreateTextureFromSurface (mpRenderer, pSurface);
  if (nullptr == pTexture)
  {
    //std::cout << "Failed to create texture : " << SDL_GetError();
    return false;
  }

  // Render the Texture with our message.
  //Setup the destination rectangle to be at the position we want
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  //Query the texture to get its width and height to use
  SDL_QueryTexture (pTexture, NULL, NULL, &dst.w, &dst.h);
  SDL_RenderCopy (mpRenderer, pTexture, NULL, &dst);

  SDL_FreeSurface (pSurface);
  SDL_DestroyTexture (pTexture);
  return true;
}

//***************************************************************************
// Function:    displayText
//
// Description: Display text on the screen at the given location. 
//              return the width and height of the text via the parameters
//              to be used to determine if a mouse click lands inside the text
//
// Parameters:  x - x position
//              y - y position
//              msg - the text to display
//              cRgba - the color of the text
//              font - the font id returned by loadFont
//              rW - the width
//              rH - the height
//
// Returned:    true or false to indicate success
//***************************************************************************
bool SDLApp::displayTextClickable (int x, int y, std::string msg, Color cRgba, 
  int font, int &rW, int &rH)
{
  SDL_Color color = { cRgba.getR (), cRgba.getG (),
    cRgba.getB (), cRgba.getA () };
  SDL_Surface *pSurface = TTF_RenderText_Blended (mcFonts.at (font - 1),
    msg.c_str (), color);
  if (nullptr == pSurface)
  {
    //std::cout << "Failed to create surface : " << SDL_GetError();
    return false;
  }

  // Map the Surface onto a Texture
  SDL_Texture *pTexture = SDL_CreateTextureFromSurface (mpRenderer, pSurface);
  if (nullptr == pTexture)
  {
    //std::cout << "Failed to create texture : " << SDL_GetError();
    return false;
  }

  // Render the Texture with our message.
  //Setup the destination rectangle to be at the position we want
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  //Query the texture to get its width and height to use
  SDL_QueryTexture (pTexture, NULL, NULL, &dst.w, &dst.h);
  SDL_RenderCopy (mpRenderer, pTexture, NULL, &dst);
  rW = dst.w;
  rH = dst.h;

  SDL_FreeSurface (pSurface);
  SDL_DestroyTexture (pTexture);
  return true;
}


//***************************************************************************
// Function:    loadSprite
//
// Description: Load the sprite's texture into a map and return the 
//              Sprite's height and width through the parameters
//
// Parameters:  name - the file name of the image
//              rW - the width
//              rH - the height
//
// Returned:    true or false to indicate success
//***************************************************************************
bool SDLApp::loadSprite (std::string name, int &w, int & h)
{
  bool bRetVal = false;

  SDL_Texture *pTexture = mcSpriteMap[name];
  if (nullptr == pTexture)
  {
    pTexture = IMG_LoadTexture (mpRenderer, name.c_str ());
    mcSpriteMap[name] = pTexture;

  }
  if (nullptr != pTexture)
  {
    SDL_QueryTexture (pTexture, NULL, NULL, &w, &h);

    bRetVal = true;
  }
  return bRetVal;
}

//***************************************************************************
// Function:    displaySprite
//
// Description: Display the sprite on the screen. The sprite holds the
//              file name and x,y coordinate
//
// Parameters:  rcSprite - the sprite to draw
//
// Returned:    None
//***************************************************************************
void SDLApp::displaySprite (const SDLSprite & rcSprite)
{
  SDL_Texture *pTexture;

  SDL_Rect rect;
  rect.x = rcSprite.getX ();
  rect.y = rcSprite.getY ();
  rect.h = rcSprite.getH ();
  rect.w = rcSprite.getW ();

  pTexture = mcSpriteMap[rcSprite.getName ()];

  if (nullptr != pTexture)
  {
    SDL_RenderCopyEx (mpRenderer, pTexture, NULL, &rect,
      rcSprite.getRotation(), NULL, SDL_FLIP_NONE);

    //SDL_RenderCopy (mpRenderer, pTexture, NULL, &rect);
  }
}

//***************************************************************************
// Function:    getFramesPerSecond
//
// Description: Return the current FramesPerSecond setting
//
// Parameters:  None
//
// Returned:    frames per second
//***************************************************************************
unsigned int SDLApp::getFramesPerSecond ()
{
  return mFramesPerSecond;
}

//***************************************************************************
// Function:    displayText
//
// Description: Display text on the screen at the given location using a 
//              default font.  
//
// Parameters:  x - x position
//              y - y position
//              msg - the text to display
//              rgba - the color of the text
//
// Returned:    none
//***************************************************************************
void SDLApp::displayText (int x, int y, std::string msg, Color cRgba)
{
  stringRGBA (this->mpRenderer, x, y, msg.c_str (),
    mcCurrentColor.getR (),
    mcCurrentColor.getG (),
    mcCurrentColor.getB (),
    mcCurrentColor.getA ());
}

//***************************************************************************
// Function:    setWindowBackgroundColor
//
// Description: Set the background color of the window.
//
// Parameters:  rgba - the new background color
//
// Returned:    none
//***************************************************************************
void SDLApp::setWindowBackgroundColor (Color cRgba)
{
  mcBackgroundColor = cRgba;
}

//***************************************************************************
// Function:    gameLoop
//
// Description: Run the game loop until a SDL_QUIT event is received.
//              This game loop sets the frames per second correctly and 
//              calls, in order: pre-loop: initGame(),  
//              in the loop: update(), render(), handleEvent().
//
// Parameters:  None
//
// Returned:    none
//***************************************************************************
void SDLApp::gameLoop ()
{
  unsigned int framesPerSecond = mFramesPerSecond;
  unsigned int startTime, endTime, delay;
  bool bIsRunning = true;
  SDL_Event uSdlEvent;
  int mouseX, mouseY;

  initGame ();
  while (bIsRunning)
  {

    startTime = SDL_GetTicks ();

    update ();

    // Set color of renderer to teal
    SDL_SetRenderDrawColor (mpRenderer,
      mcBackgroundColor.getR (),
      mcBackgroundColor.getG (),
      mcBackgroundColor.getB (),
      mcBackgroundColor.getA ());

    // Clear the window and make it all teal
    SDL_RenderClear (mpRenderer);

    render ();


    // Render the changes above
    SDL_RenderPresent (mpRenderer);

    uSdlEvent.type = SDL_FIRSTEVENT;

    if (SDL_PollEvent (&uSdlEvent) != 0)
    {
      if (uSdlEvent.type == SDL_QUIT ||
        (uSdlEvent.type == SDL_WINDOWEVENT &&
          uSdlEvent.window.event == SDL_WINDOWEVENT_CLOSE
          )
        )
      {
        bIsRunning = false;
      }


      if (mbEnableTextInput)
      {
        if (uSdlEvent.type == SDL_MOUSEBUTTONDOWN &&
          uSdlEvent.button.button == SDL_BUTTON_LEFT)
        {
          mouseX = uSdlEvent.button.x;
          mouseY = uSdlEvent.button.y;

          mpFocusTextWidget = nullptr;
          for (auto it = mcTextWidgetVector.begin ();
            it != mcTextWidgetVector.end (); ++it)
          {
            (*it)->setFocus (false);
            if ((*it)->clicked (mouseX, mouseY) &&
              (*it)->isEditable ())
            {
              (*it)->setFocus (true);
              mpFocusTextWidget = (*it);
              SDL_StartTextInput ();
              mbTextInputActive = true;
            }
          }
          if (nullptr == mpFocusTextWidget)
          {
            SDL_StopTextInput ();
            mbTextInputActive = false;
          }
        }
        handleTextEvent (uSdlEvent);
      }


      if (uSdlEvent.type == SDL_MOUSEBUTTONDOWN &&
        uSdlEvent.button.button == SDL_BUTTON_LEFT)
      {
        mouseX = uSdlEvent.button.x;
        mouseY = uSdlEvent.button.y;

        for (auto it = mcClickWidgetVector.begin ();
          it != mcClickWidgetVector.end (); ++it)
        {
          if ((*it)->clicked (mouseX, mouseY))
          {
            (*it)->clickEventHandler ();
          }
        }
      }



  
      handleEvent (uSdlEvent);
    }

    // decide how fast to update the screen.
    if (-1 != framesPerSecond)
    {
      // force a particular number of frames per second
      endTime = SDL_GetTicks ();
      if (1000 / framesPerSecond > endTime - startTime)
      {
        delay = 1000 / framesPerSecond - (endTime - startTime);
        SDL_Delay (delay);
        // uncomment to see how much of a delay is needed.
        //cout << delay << " ";
      }
    }
    else
    {
      // just delay for 1 millisecond
      SDL_Delay (1);
    }

  }
}

//***************************************************************************
// Function:    enableTextInput
//
// Description: Turn on text event handling
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void SDLApp::enableTextInput ()
{
  mbEnableTextInput = true;
}

//***************************************************************************
// Function:    disableTextInput
//
// Description: Turn off text event handling
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void SDLApp::disableTextInput ()
{
  mbEnableTextInput = false;
}

//***************************************************************************
// Function:    registerTextWidget
//
// Description: Register a text widget that is involved in text events
//
// Parameters:  pcWidet - the text widget
//
// Returned:    None
//***************************************************************************
void SDLApp::registerTextWidget (ISDLWidgetTextable * pcWidget)
{
  mcTextWidgetVector.push_back (pcWidget);
}

//***************************************************************************
// Function:    registerClickableWidget
//
// Description: Register a clickable widget that is involved in click events
//
// Parameters:  pcWidet - the clickable widget
//
// Returned:    None
//***************************************************************************
void SDLApp::registerClickableWidget (ISDLWidgetClickable * pcClickable)
{
  mcClickWidgetVector.push_back (pcClickable);
}

//***************************************************************************
// Function:    update
//
// Description: default implementation of update()
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void SDLApp::update ()
{
}

//***************************************************************************
// Function:    initGame
//
// Description: default implementation of initGame()
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void SDLApp::initGame ()
{
}

//***************************************************************************
// Function:    handleEvent
//
// Description: default implementation of update()
//
// Parameters:  event - the event to handle
//
// Returned:    none
//***************************************************************************
void SDLApp::handleEvent (SDL_Event uEvent)
{

}

//***************************************************************************
// Function:    handleTextEvent
//
// Description: Handle text events for register Text Widgets
//
// Parameters:  event - the event to handle
//
// Returned:    none
//***************************************************************************
void SDLApp::handleTextEvent (SDL_Event event)
{
  std::string tmpString;

  if (mbTextInputActive)
  {
    tmpString = mpFocusTextWidget->getData ();
    if (SDL_KEYDOWN == event.type)
    {
      if (SDLK_BACKSPACE == event.key.keysym.sym)
      {
        if (tmpString.length () > 0)
        {
          tmpString.pop_back ();
          mpFocusTextWidget->setData (tmpString);
        }
      }
      else if (SDLK_RETURN == event.key.keysym.sym ||
        SDLK_RETURN2 == event.key.keysym.sym)
      {
        SDL_StopTextInput ();
        mbTextInputActive = false;
        mpFocusTextWidget->stateChangeEvent ();
        mpFocusTextWidget->setFocus (false);
        mpFocusTextWidget = nullptr;
      }

    }
    else if (SDL_TEXTINPUT == event.type)
    {
      tmpString += event.text.text;
      mpFocusTextWidget->setData (tmpString);
    }
  }
}

//***************************************************************************
// Destructor:  ~SDLApp
//
// Description: Calls cleanup() to deallocate SDL memory
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
SDLApp::~SDLApp ()
{
  cleanup ();
}

//***************************************************************************
// Function:    cleanup
//
// Description: deallocate SDL memory.
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void  SDLApp::cleanup ()
{
  if (nullptr != mpRenderer || nullptr != mpWindow)
  {
    for (auto iter : mcFonts)
    {
      TTF_CloseFont (iter);
    }

    for (const auto &value : mcSpriteMap)
    {
      SDL_DestroyTexture (value.second);
    }
    SDL_DestroyRenderer (mpRenderer);
    SDL_DestroyWindow (mpWindow);
    SDL_Quit ();
    mpRenderer = nullptr;
    mpWindow = nullptr;
  }
}
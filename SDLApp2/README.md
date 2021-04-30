## SDLApp Documentation


### SDLApp

The main UI loop and SDL interface. Subclass this class and implement at least
```
void render()
```
to draw your items on the screen.

---

```
void gameLoop (unsigned int framesPerSecond = 60);
```
Invoke to start the UI Loop. The gameLoop will run the following functions 
at the appropriate time. initGame() is run once before the game loop starts. update() is run immediately at the top of the game loop. This function  
should process any changes to your displayed items but render the items on the 
screen. render() is called next and should draw all of your items on the screen. handleEvent(SDL_Event event) is called after items have been drawn to the 
screen. handleTextEvent(SDL_Event event) is called if a text input event happens.

---

```
void initGame ();
void update ();
void handleEvent (SDL_Event event);

void handleTextEvent (SDL_Event event); 
void render () = 0;
```
Override the above methods to customize your application.

---

```
 void setColor (Color cRgba)
 Color getColor () const
```
Set and retreive the current color. This color will be used by drawLine() 
and drawCircle().

---


```
 void drawLine (int x1, int y1, int x2, int y2);
 void drawCircle (int x, int y, int radius);
```
Draw a line or a circle using the current color.

---



 ```

 void displayText (int x, int y, std::string msg, Color cRgba);

 int loadFont (std::string fontname, int size);
 bool displayText (int x, int y, std::string msg, Color cRgba, int font);
 bool displayTextClickable (int x, int y, std::string msg, Color cRgba, 
  int font, int &w, int &h);

```

displayText() will use the default SDL font to display the msg at the given location,
using the given Color.
 
loadFont() will load a font from the given filename (fontname) using the given size.
The returned int can be used to access this font for the second instance of displayText()
which takes an int as its last argument.

displayTextClickable() displays the text using a font and returns through the 
parameter list the length and height of the font on the screen. This can be used
to determine the bouning box for mouse clicks.

---

```
 bool loadSprite (std::string name, int &w, int &h);
 void displaySprite (const SDLSprite &rcSprite);
```
loadSprite() will load an image from the given file name (name) and return that
images width and height through the parameter list. The returned bool will notify the
caller if the load was successful.

displaySprite(SDLSprite &) will display the SDLSprite by looking at the contained
filename, x,y coordinate and w,h settings.

---

```
 void enableTextInput ();
 void disableTextInput ();

```
Call these functions to either enable or disable text input handling.

---

```
void registerTextWidget (ISDLWidgetTextable *pcWidget);
void registerClickableWidget (ISDLWidgetClickable *pcClickable);

```

registerTextWidget(ISDLWidgetTextable *) allows the user to register a text widget with SDLApp
and have SDLApp manage all the draw() calls, text input handling, and stateChangeEvent() invocations
for the user.

registerClickableWidget(ISDLWidgetClickable *) allows the user to register a clickable widget with SDLApp
and have SDLApp manage all the draw() calls and clickEventHandler() invocations for the user.

A user does not need to register a text widget via registerClickableWidget() unless the widget needs
to invoke clickEventHandler(). Clicking on a text widget to gain focus is handled completely by registerTextWidget()


### Color

A basic rgba Color class with an extraction (operator>>) operator. 

### ISDLWidget

Abstract parent class for all UI Widgets on the screen.

```
virtual void draw(SDLApp &) = 0;
```
override in child class to draw the widget 

---
```
virtual bool isVisible() 
virtual void setVisible(bool)
```
check and set visiblity of the widget to 
show or hide the widget 

### ISDLWidgetClickable

Abstract parent class for clickable UI Widgets on the screen.

```
virtual bool clicked(int x, int y) = 0; 
```
override in child class to inform if the widget has been 
clicked. The x,y parameters are the position of the mouse click 
 on the screen. 

---
```
virtual void registerClickEventHandler(std::function<void(void)>); 
```
set a function to be called via clickEventHandler(). 
The function provided must be void(void) OR be a function<> object with all
of its parameters bound via std\::bind.  An example of using bind:

```
auto func = std::bind 
(&TicTacToeView_SDL::onSetPlayer1NameWidget, this, &mcPlayer1Name)
```

The above example produces a std::function<void(void)> object that calls 
the function onSetPlayer1NameWidget on the this object using as a 
parameter, &mcPlayer1Name. 
the following example shows how to use func.
```
func();
// is now eqivalent to
this->onSetPlayer1Name(&mcPlayer1Name);
```

---

```
virtual void clickEventHandler();
```
invoke the function specified to registerClickEventHandler


### ISDLWidgetTextable

```
void setData(string);
string getData(string);
```
Access the string data displayed in the Widget.

---

```
void setLabel(string);
string getLabel(string);
```
Access the label data displayed in the Widget.

---

```
void setEditable(bool)
bool isEditable()
```
Specify and check if the user can edit the text in the Widget.

---

```
void setFocus(bool)
bool hasFocus()
```
Specify and check if the widget currently has focus on the screen. 
All text input events go to the Text Widget with focus. Only one widget 
may have focus at a time.

---

```
void stateChangeEvent()
void registerStateChangeEventHandler(std::function<void(void)>)
```

Set and call a function in response to a state change event. A state change 
event occurs when the text widget has focus and the user presses the
return key.

The function provided must be void(void) OR be an std
::function<> object with all of its parameters bound via std\::bind.

An example of using std\::bind is above in ISDLWidgetClickable.

### SDLTextWidget

A basic text widget. The text is displayed on the screen as:
```
Label: Data
```
or, if there is no label:
```
Data
```

```
int getLength()
```
Return the total number of characters to be displayed.


---

```
bool clicked(int x, int y)
```
Returns true if the x, y coordinate provided is within the text widget's 
screen space.

### SDLSprite

Basic image displayed on the screen.

```
bool loadSprite(SDLApp *, string file, int x, int y)
```
Load the image given by filename file into SDLApp. The Sprite is positioned 
at location x, y. False is returned if the image could not be loaded.

---

```
int getX()
int getY()
int getH()
int getW()
```
Get the x,y coordinates and the height and width of the Sprite.

---
```
string getName()
```
Get the name of the file containing the Sprite. 

---
```
void draw(SDLApp&)
```
Draw the Sprite at the correct location on the screen

---
``` 
bool clicked(int x, int y)
```
Returns true if the x, y coordinate provided is within the Sprite's 
screen space.

#include <iostream>
#include <map>
#include <string>
#include <windows.h>
using namespace std;

void type_effect(string text, int speed)

{
    for (int i = 0; i < text.length(); i++)
    {
        cout << text[i] << flush;
        Sleep(speed);
    }
    cout << endl;
}

void fix_watch(map<string, bool> &gameState);
void watchcode(map<string, bool> &gameState);

void pocket(map<string, bool> &gameState)
{

    map<string, string> pocket;

    pocket["watch_found"] = "Slot 1 : You have a broken antique watch inside your pocket.\n";
    pocket["watch_empty"] = "Slot 1 : <-------- The slot is empty --------->\n";
    pocket["watch_fixed"] = "Slot 1 [WATCH]: You have a repaired antique watch inside your pocket.";

    pocket["hand_found"] = "Slot 2 : You have a watch hour hand inside your pocket.\n";
    pocket["hand_empty"] = "Slot 2 : <-------- The slot is empty --------->\n";

    pocket["all_empty"] = "\n<---- Your inventory pocket is completely empty ---->\n";
    if (gameState["watchFixed"] == false)
    {
        if (gameState["watchinhand"] == false)
        {
            cout << pocket["watch_empty"];
        }
        else if (gameState["watchinhand"] == true)
        {
            cout << pocket["watch_found"];
        }
        if (gameState["hand"] == false)
        {
            cout << pocket["hand_empty"];
        }
        else if (gameState["hand"] == true)
        {
            cout << pocket["hand_found"];
        }
        if (gameState["watchinhand"] == false && gameState["hand"] == false)
        {
            cout << pocket["all_empty"];
        }

        if (gameState["watchinhand"] == true && gameState["hand"] == true)
        {
            
            
                cout << endl;

                type_effect("VOID :- You have a new action available!", 40);
                type_effect("As you have collected the necessary parts, you can now fix the watch.", 35);
                cout << "--------------------------------------------------------" << endl;
                type_effect("1. fix_watch  -=- (To fix the broken watch)", 30);
                type_effect("2. back       -=- (To return to the previous window)", 30);
                cout << "--------------------------------------------------------" << endl;

                string fix;
                while (true)
                {
                    cout << "Choice: ";
                    cin >> fix;

                    if (fix == "fix_watch")
                    {
                        fix_watch(gameState);
                        break;
                    }
                    else if (fix == "back")
                    {
                        break;
                    }
                    else
                    {
                        cout << "<--------------- PLEASE ENTER A VALID INPUT --------------->" << endl;
                    }
                
            }
        }}

        else if (gameState["watchFixed"] == true)
        {
            cout << pocket["watch_fixed"];
            cout << "(To check time) check_time" << endl;
            cout<<"Choice : ";
            string time;
            cin>>time;
            if (time == "check_time")
            {
                if (gameState["timecode"] == true)
                {
                    cout << "THE WATCH DISPLAYES [7:50]";
                }
                else if (gameState["timecode"] == false)
                {
                    cout << "THE TIME IS UNSET" << endl;
                    watchcode(gameState);
                }
            }
        }
    }


void fix_watch(map<string, bool> &gameState)
{
    int speed = 35;

    cout << endl;
    type_effect(" //==================================================\\\\", 15);
    type_effect("||                    REPAIRING WATCH                  ||", 15);
    type_effect(" \\\\==================================================//", 15);
    cout << endl;

    type_effect("[ You carefully steady your hands and align the broken components ]", 45);
    type_effect("With a delicate click, the loose brass hour hand snaps perfectly onto the center pin.", speed);
    type_effect("Suddenly, the dead internal gears click, whir, and spark to life!", speed);
    type_effect("The tick-tick-tick of the old gears echoes softly in your palm.", speed);

    cout << endl;
    type_effect("The watch is fixed, but the hands are pointing completely randomly.", speed);
    type_effect("A tiny mechanical crown dial on the side allows you to set the hands manually.", speed);
    cout << endl;
    gameState["watchFixed"] = true;
    watchcode(gameState);
}

void watchcode(map<string, bool> &gameState)
{
    while (true)
    {
        string time_input;
        int speed = 35;

        type_effect("What time will you dial into the watch? (Format: HH:MM or type 'back')", speed);
        cout << "Set Time > ";
        cin >> time_input;

        if (time_input == "back")
        {
            break;
        }
        else if (time_input == "12:00" || time_input == "12")
        {
            cout << endl;
            int speed = 35;
            type_effect("[ THE INTERNAL COGS WHIRR FURIOUSLY ]", 50);
            type_effect("The moment the hands hit twelve, the watch locks up tightly.", 35);
            type_effect("The gears begin revolving automatically at blinding speed!", speed);
            type_effect("The hands spin backward and forward, fighting against your control...", speed);

            cout << endl;
            type_effect("Suddenly, everything snaps completely still.", 55);
            type_effect("The clock hands settle firmly onto a completely new position.", speed);

            cout << endl;
            type_effect("   =====================================================", 15);
            type_effect("   |        ** THE FIXED WATCH DISPLAYS: 07:50 **       |", 50);
            type_effect("   =====================================================", 15);
            cout << endl;

            type_effect("A tiny numeric stamp shifts into view on the digital lock dial below the hands.", speed);

            gameState["timecode"] = true;

            break;
        }
        else
        {
            cout << "\n<------ THE GEARS JAM. NOTHING HAPPENS. INCORRECT TIME ------>\n"
                 << endl;
        }
    }
}

// <<-------------------------------------------------- FUCTION PRE-DECLIREASION -------------------------------------------->>

void table(map<string, bool> &gameState, string &way);
void north_wall_inspect(map<string, bool> &gameState, string &way);
void north_wall_intro(map<string, bool> &gameState, string &way);
void south_wall_intro(map<string, bool> &gameState, string &way);
void south_wall_intro_north(map<string, bool> &gameState, string &way);
void inspect_box(map<string, bool> &gameState, string &way);
void north_wall(map<string, bool> &gameState, string &way);
void south_wall(map<string, bool> &gameState, string &way);
void west_wall(map<string, bool> &gameState, string &way);
void east_wall(map<string, bool> &gameState, string &way);
void shelf_intro(map<string, bool> &gamState, string &way);
void cover_letter();
void open_drawr(map<string, bool> &gameState, string &way);
void box_open(map<string, bool> &gameState, string &way);
void east_wall_intro(map<string, bool> &gameState, string &way);
void inspect_painting(map<string, bool> &gameState, string &way);
void west_wall_intro(map<string, bool> &gameState, string &way);
void west_inspect_painting(map<string, bool> &gameState, string &way);
void inspect_door(map<string, bool> &gameState, string &way);

void intro()
{
    int speed = 50;

    int dramatic_speed = 100;
    cout << endl;
    cout << endl;
    type_effect("You wake up on a cold, hard floor.", speed);
    Sleep(1000);
    type_effect("Your head throbs. The air feels heavy, metallic, and completely still.", speed);
    Sleep(1000);
    type_effect("As your eyes adjust to the dim light, you realize you are inside a windowless, hexagonal chamber made of polished black stone.", speed);
    Sleep(1500);

    cout << endl;

    type_effect("A low hum echoes through the floorboards.", speed);
    type_effect("Directly ahead, a massive steel vault door blocks the only exit.", speed);
    type_effect("A digital keypad on the door glows blood-red, demanding a 6-digit code.", speed);
    Sleep(1500);

    cout << endl;

    type_effect("Suddenly, a synthetic voice crackles through a hidden speaker above:", dramatic_speed);
    Sleep(500);
    type_effect("\"SPEAKER :- Welcome, subject. You are locked inside the Chronos Sanctuary.\"", speed);
    type_effect("\"SPEAKER :- To escape, you must solve the riddle of the four cardinal directions.\"", speed);
    type_effect("\"SPEAKER :- Look North, East, South, and West. Gather the clues. Connect the pieces.\"", speed);
    type_effect("\"SPEAKER :- You have one room. One code. One chance. Begin.\"", dramatic_speed);
    Sleep(1000);

    cout << endl;

    type_effect("The speaker cuts out. In the dead center of the room, a stone pedestal lights up.", speed);
    type_effect("Engraved on its surface are the words:", speed);
    type_effect("-> \"Time binds the four corners of reality.\" <-", dramatic_speed);
    Sleep(1000);

    cout << endl;
}

// <<-------------------------------------------------- SUB JUCTION WALLS -------------------------------------------->>

// <<-----NORTH---->
void north_wall(map<string, bool> &gameState, string &way)
{
    string north_opp;
    map<string, void (*)(map<string, bool> &, string &)> north;
    north["table"] = table;
    north["wall_inspect"] = north_wall_inspect;
    north["wall_intro"] = north_wall_intro;

    while (true)
    {
        if (gameState["northVisited"] == false)
        {
            north_wall_intro(gameState, way);
            gameState["northVisited"] = true;
        }

        else if (gameState["northVisited"] == true)
        {
            type_effect(" //==================================================\\\\", 15);
            type_effect("||                      NORTH WALL                     ||", 15);
            type_effect(" \\\\==================================================//", 15);
            cout << endl;
            type_effect("VOID :- What will you do next?", 45);
            cout << "--------------------------------------------------------" << endl;

            cout << "table        -=- (To inspect the table)" << endl;
            cout << "wall_inspect -=- (To inspect the wall in detail)" << endl;
            cout << "wall_intro   -=- (To listen to the wall introduction)" << endl;
            cout << "open_pocket  -=- (To open your inventory)" << endl;
            cout << "trun         -=- (To change direction )" << endl;

            cout << "--------------------------------------------------------" << endl;
            cout << endl;
        }

        cout << "Choice : ";
        cin >> north_opp;
        if (north.count(north_opp) > 0)
        {
            north[north_opp](gameState, way);
            cout << endl;
            cout << "\nVOID :- What will you do next inside NORTH? (table / wall_inspect / wall_intro / south / east / west)\n Choice: ";
        }
        else if (north_opp == "turn")
        {
            // way=north_opp;
            break;
        }
        else if (north_opp == "open_pocket")
        {
            pocket(gameState);
        }
        else if (north_opp == "back")
        {
            break;
        }
        else
        {
            cout << "<------ PLEASE INPUT A VALID INPUT ------>" << endl;
        }
    }
}

// <<-----SOUTH---->

void south_wall(map<string, bool> &gameState, string &way)
{
    string south;
    while (true)
    {
        if (gameState["northVisited"] == false && gameState["southVisited"] == false)
        {
            south_wall_intro(gameState, way);
            gameState["northVisited"] = true;
            gameState["southVisited"] = true;
        }
        else if (gameState["northVisited"] == true && gameState["southVisited"] == false)
        {
            south_wall_intro_north(gameState, way);
            gameState["southVisited"] = true;
        }
        else if (gameState["southVisited"] == true)
        {
            cout << endl;
            type_effect(" //==================================================\\\\", 15);
            type_effect("||                     SOUTH WALL                      ||", 15);
            type_effect(" \\\\==================================================//", 15);
            cout << endl;
            type_effect("What would you like to do?", 30);
            cout << "1. inspect_shelf (Inspect the shelf)" << endl;
            cout << "2. inspect_box   (Inspect the wooden box)" << endl;
            cout << "3. back          (GO BACK)" << endl;
            cout << "4. open_pocket   (open the inventory)" << endl;
            cout << "5. turn          (To change direction)" << endl;
            cout << endl;
        }

        cout << "CHOICE :";
        cin >> south;

        if (south == "inspect_shelf")
        {
            shelf_intro(gameState, way);
        }
        else if (south == "inspect_box")
        {
            inspect_box(gameState, way);
        }
        else if (south == "wall_intro")
        {
            south_wall_intro(gameState, way);
        }
        else if (south == "turn")
        {
            // way=south;
            break;
        }
        else if (south == "back")
        {
            break;
        }
        else if (south == "open_pocket")
        {
            pocket(gameState);
        }
        else
        {
            cout << "<------ PLEASE INPUT A VALID INPUT ------>" << endl;
        }
    }
}

// <<-----WEST---->

void west_wall(map<string, bool> &gameState, string &way)
{
    while (true)
    {
        if (gameState["westVisited"] == false)
        {
            west_wall_intro(gameState, way);
            gameState["westVisited"] = true;
        }
        else if (gameState["westVisited"] == true)
        {
            cout << endl;
            type_effect(" //==================================================\\\\", 15);
            type_effect("||                      WEST WALL                      ||", 15);
            type_effect(" \\\\==================================================//", 15);
            cout << endl;
            type_effect("What would you like to do?", 30);
            cout << "1. inspect_painting (Look closely at the painting)" << endl;
            cout << "2. inspect_door     (Step closer to examine the exit door)" << endl;
            cout << "3. back             (To go back)" << endl;
            cout << "4. open_pocket      (To excess the inventory)" << endl;
            cout << endl;
        }
        string west;
        cout << "Choice : ";
        cin >> west;
        if (west == "inspect_door")
        {
            inspect_door(gameState, way);
        }
        else if (west == "inspect_painting")
        {
            west_inspect_painting(gameState, way);
        }
        else if (west == "back")
        {
            break;
        }
        else if (west == "open_pocket")
        {
            pocket(gameState);
        }
    }
}

// <<-----EAST---->

void east_wall(map<string, bool> &gameState, string &way)
{
    string east;
    while (true)
    {
        if (gameState["eastVisited"] == false)
        {
            east_wall_intro(gameState, way);
            gameState["eastVisited"] = true;
        }
        else if (gameState["eastVisited"] == true)
        {
            cout << endl;
            type_effect(" //==================================================\\\\", 15);
            type_effect("||                     EAST WALL                       ||", 15);
            type_effect(" \\\\==================================================//", 15);
            cout << endl;
            type_effect("What would you like to do?", 30);
            cout << "1. inspect_painting (Look closely at the painting and inscription)" << endl;
            cout << "2. back            (To go back)" << endl;
            cout << "3. open_pocket     (To excess the inventory)" << endl;
            cout << "4. enter_code      (To enter the passwrod on the digital lock)" << endl;
            cout << endl;
        }
        cout << "Choice : ";
        cin >> east;
        if (east == "inspect_painting")
        {
            inspect_painting(gameState, way);
        }
        else if (east == "back")
        {
            break;
        }
        else if (east == "open_pocket")
        {
            pocket(gameState);
        }
        else if (east == "enter_code")
        {
            if (gameState["digitalcode"] == false)
            {
                int speed = 35;
                string pass_attempt;

                cout << endl;
                type_effect(" //==================================================\\\\", 15);
                type_effect("||               🔐  EAST DIGITAL PANEL  🔐           ||", 15);
                type_effect(" \\\\==================================================//", 15);
                cout << endl;

                type_effect("The electronic screen blinks steadily, glowing in the dim light.", speed);
                type_effect("The security terminal demands a 6-character alphabetical code to unlock.", speed);
                type_effect("(Type 'back' to cancel and step away)", speed);
                cout << endl;

                while (true)
                {
                    cout << "Enter Alphabetical Password: ";
                    cin >> pass_attempt;

                    if (pass_attempt == "back")
                    {
                        break;
                    }
                    else if (pass_attempt == "oxygen" || pass_attempt == "OXYGEN")
                    {
                        cout << endl;
                        type_effect("[ DIGITAL LOCK ]", 50);
                        type_effect("The security interface accepts the word! A small metal compartment pops open.", speed);
                        type_effect("Inside, a brilliant neon terminal flashes a series of data values:", speed);

                        cout << endl;
                        type_effect("   =====================================================", 15);
                        type_effect("   |       ** PANEL DISCOVERY DECRYPTED: 816 **        |", 50);
                        type_effect("   =====================================================", 15);
                        cout << endl;

                        type_effect("You memorize the digitsd.", speed);
                        gameState["digitalcode"] = true;
                        break;
                    }
                    else if (pass_attempt == "open_pocket")
                    {
                        pocket(gameState);
                    }
                    else
                    {
                        cout << "<------ ACCESS DENIED. KEYWORD NOT RECOGNIZED BY SYSTEM ------>" << endl;
                    }
                }
            }
            else
            {
                cout << "<------ PLEASE INPUT A VALID INPUT ------>" << endl;
                
            }
        }
        else if (gameState["digitalcode"] == true)
        {
            cout << endl;
            type_effect("VOID :- The digital panel is already unlocked. Its screen steadily displays: [ 816 ]", 35);
            cout << endl;
        }
    }
}

// <<--------------------------------------------------WEST WALL-------------------------------------------->>

void west_wall_intro(map<string, bool> &gameState, string &way)
{
    int speed = 35;

    cout << endl;
    type_effect(" //==================================================\\\\", 15);
    type_effect("||                      WEST WALL                      ||", 15);
    type_effect(" \\\\==================================================//", 15);
    cout << endl;

    // Wall Description
    type_effect("You turn your body to face the WEST wall.", speed);
    type_effect("This side of the chamber carries a different energy altogether.", speed);

    cout << endl;

    // The Painting and The Door
    type_effect("Hanging cleanly on the stone is another interesting painting.", speed);
    type_effect("Directly beside it, a massive vault door stands firmly embedded in the rock.", speed);
    type_effect("Its reinforced metal plating gleams under the pale light, offering a sudden spark of hope.", speed);
    type_effect("Yet, its sheer size makes it clear—this structural barrier cannot be forced open by power alone.", speed);
    type_effect("A localized electronic locking module blinks silently, demanding a password code.", speed);

    cout << endl;

    type_effect("What would you like to do?", speed);
    cout << "1. inspect_painting (Look closely at the painting)" << endl;
    cout << "2. inspect_door     (Step closer to examine the exit door)" << endl;
    cout << "3. back             (To go back)" << endl;
    cout << "4. open_pocket      (To excess the inventory)" << endl;
    cout << endl;
}

void west_inspect_painting(map<string, bool> &gameState, string &way)
{
    int speed = 35;
    string player_input;

    cout << endl;
    type_effect(" //==================================================\\\\", 15);
    type_effect("||                  THE WEST PAINTING                   ||", 15);
    type_effect(" \\\\==================================================//", 15);
    cout << endl;

    type_effect("[ You step close to examine the haunting West canvas ]", 45);
    cout << endl;

    type_effect("This oil painting is dark, chaotic, and deeply unsettling.", speed);
    type_effect("It depicts a frantic, desperate man drowning beneath deep, suffocating water.", speed);
    type_effect("His face is twisted in agony, staring helplessly toward the surface.", speed);

    cout << endl;
    type_effect("His wide eyes are desperately tracking an array of rising water bubbles.", speed);
    type_effect("You lean closer and realize each tiny bubble holds the chemical signature of life...", speed);
    type_effect("They are escaping his grasp, taking away the precious air he needs to survive.", speed);

    cout << endl;
    type_effect("   =====================================================", 15);
    type_effect("   |                ** LIFE SLIPS AWAY **               |", 45);
    type_effect("   =====================================================", 15);
    cout << endl;

    type_effect("The imagery is terrifying, directly pointing your attention to that specific movment/expirence.", speed);
    type_effect("What do you want to do? (Type 'back' to step away from the painting)", speed);
    cout << endl;

    while (true)
    {
        cout << "Choice : ";
        cin >> player_input;

        if (player_input == "back")
        {
            break;
        }
        else
        {
            cout << "<------ PLEASE INPUT A VALID INPUT ------>" << endl;
        }
    }
}

void inspect_door(map<string, bool> &gameState, string &way)
{
    int speed = 35;
    string code_attempt;

    cout << endl;
    type_effect(" //==================================================\\\\", 15);
    type_effect("||               🚪  THE EXIT VAULT  🚪               ||", 15);
    type_effect(" \\\\==================================================//", 15);
    cout << endl;

    type_effect("[ You step close to the cold, massive steel barrier ]", 45);
    cout << endl;

    type_effect("Up close, the vault door feels absolutely indestructible.", speed);
    type_effect("Heavy industrial rivets seal the plating into the solid stone frame.", speed);
    type_effect("Mounted securely into the center of the steel is a glowing digital lock.", speed);
    type_effect("It features a rugged, metallic number pad backlit by a piercing red light.", speed);
    cout << endl;

    type_effect("The display screen blinks steadily, demanding a 6-digit password.", speed);
    type_effect("(Type 'back' to step away from the keypad panel)", speed);
    cout << endl;

    while (true)
    {
        cout << "Enter 6-Digit Code : ";
        cin >> code_attempt;

        if (code_attempt == "back")
        {
            break;
        }

        else if (code_attempt == "750816")
        {
            cout << endl;
            type_effect("[⚡ DEEP MECHANICAL HUM RUMBLES ⚡]", 50);
            type_effect("The digital screen flashes a brilliant emerald green!", speed);
            type_effect("Heavy internal steel bolts slide backward one by one.", speed);
            type_effect("The massive vault door slowly swings inward, revealing a bright light.", speed);
            cout << endl;
            type_effect("VOID :- Congratulations ! You have successfully escaped the Chronos Sanctuary.", 60);

            exit(0);
        }
        else
        {
            cout << "<------ ACCESS DENIED. DIGITAL LOCK ALARMS FLASH RED ------>" << endl;
        }
    }
}

// <<--------------------------------------------------EAST WALL-------------------------------------------->>

void east_wall_intro(map<string, bool> &gameState, string &way)
{
    int speed = 25;
    int intense_speed = 45;
    cout << endl;
    type_effect(" //==================================================\\\\", 15);
    type_effect("||                     EAST WALL                      ||", 15);
    type_effect(" \\\\==================================================//", 15);
    cout << endl;

    type_effect("You turn slowly to face the EAST wall.", speed);
    type_effect("A heavy, suffocating silence hangs over this side of the dark stone chamber.", speed);

    cout << endl;

    type_effect("Hanging directly in the center is a massive, unsettling oil painting.", speed);
    type_effect("The canvas depicts a distorted face emerging from absolute darkness.", speed);
    type_effect("Two frantic, desperate eyes stare back out at you with terrifying intensity.", intense_speed);
    type_effect("No matter where you step, they seem to follow, boring directly into your very soul.", intense_speed);

    cout << endl;

    type_effect("Your gaze drops to the bottom of the canvas.", speed);
    type_effect("Scrawled aggressively across the gold frame is a faint, cryptic inscription.", speed);
    type_effect("The jagged handwriting looks like it was scratched in a state of pure panic.", speed);

    cout << endl;

    type_effect("Right below the framing, a small digital panel blinks in the shadow.", speed);
    type_effect("It hides a secret passcode, waiting for a keyword to reveal its contents.", speed);
    cout << endl;

    type_effect("What would you like to do?", speed);
    cout << "1. inspect_painting (Look closely at the painting and inscription)" << endl;
    cout << "2. back            (To go back)" << endl;
    cout << "3. open_pocket     (To excess the inventory)" << endl;
    cout << "4. enter_code      (To enter the passwrod on the digital lock)" << endl;
    cout << endl;
}

void inspect_painting(map<string, bool> &gameState, string &way)
{
    int speed = 35;
    string input;

    cout << endl;
    type_effect(" //==================================================\\\\", 15);
    type_effect("||               🖼️  THE PAINTING  🖼️                 ||", 15);
    type_effect(" \\\\==================================================//", 15);
    cout << endl;

    type_effect("[ You step closer, forced to look straight into the canvas ]", 45);
    cout << endl;

    // Detailed Keyboard Art focusing only on the desperate eyes
    cout << "     , - - .                   , - - .     " << endl;
    cout << "   /  \\ | /  \\               /  \\ | /  \\   " << endl;
    cout << "  | -  (O)  - |             | -  (O)  - |  " << endl;
    cout << "   \\  / | \\  /               \\  / | \\  /   " << endl;
    cout << "     ` - - '                   ` - - '     " << endl;
    cout << endl;

    type_effect("Two wide, frantic eyes glare directly out from the canvas.", speed);
    type_effect("They look completely terrified, bloodshot and paralyzed with a quiet panic.", speed);
    type_effect("Etched deeply into the center frame, you read the bold message:", speed);
    cout << endl;

    type_effect("   =====================================================", 15);
    type_effect("   |             ** WHAT I SEE, YOU SEE **             |", 45);
    type_effect("   =====================================================", 15);
    cout << endl;

    type_effect("The words are clear, but their true meaning remains hidden.", speed);
    type_effect("What do you want to do? (Type 'back' to step away from the painting)", speed);
    cout << endl;

    while (true)
    {
        cout << "Choice : ";
        cin >> input;

        if (input == "back")
        {
            break;
        }
        else
        {
            cout << "<------ PLEASE INPUT A VALID INPUT ------>" << endl;
        }
    }
}

// <<--------------------------------------------------SOUTH WALL-------------------------------------------->>

void shelf_intro(map<string, bool> &gameState, string &way)
{
    int speed = 35;
    string shelf;
    while (true)
    {
        if (gameState["shelfvisit"] == false)
        {
            cout << endl;
            type_effect(" //==================================================\\\\", 15);
            type_effect("||                    THE DISPLAY SHELF                ||", 15);
            type_effect(" \\\\==================================================//", 15);
            cout << endl;

            type_effect("[ You step closer to look closely at the display shelf ]", 45);
            cout << endl;
            type_effect("Up close, the shelf is remarkably well-maintained.", speed);
            type_effect("Its clean, polished wood catches the ambient light, showing a smooth, glossy surface.", speed);

            cout << endl;

            type_effect("There, sitting prominently on the tier, you see the wooden box again.", speed);
            type_effect("It looks incredibly interesting—crafted with tight joints and a heavy iron mechanism.", speed);
            type_effect("Leaning in, you notice an intricate carving etched directly into its wooden lid.", speed);

            cout << endl;
            type_effect("Surrounding it, several old books line the rest of the space.", speed);
            type_effect("They hold no real utility, serving only to give the shelf a complete, fulfilling feeling.", speed);
            cout << endl;
            gameState["shelfvisit"] = true;
        }
        else if (gameState["shelfvisit"] == true)
        {
            cout << endl;
            type_effect(" //==================================================\\\\", 15);
            type_effect("||                    THE DISPLAY SHELF                ||", 15);
            type_effect(" \\\\==================================================//", 15);
            cout << endl;
            type_effect("What next? (Type: inspect_box / back)", speed);
        }
        cout << "Choice : ";

        cin >> shelf;

        if (shelf == "inspect_box")
        {
            inspect_box(gameState, way);
        }
        else if (shelf == "back")
        {
            break;
        }
        else if (shelf == "pocket")
        {
            pocket(gameState);
        }
        else
        {
            cout << "<------ PLEASE INPUT A VALID INPUT ------>" << endl;
        }
    }
}

void inspect_box(map<string, bool> &gameState, string &way)
{
    int speed = 35;
    string pass, code;
    while (true)
    {
        if (gameState["wodenbox"] == false)
        {
            cout << endl;
            type_effect(" //==================================================\\\\", 15);
            type_effect("||                    THE WOODEN BOX                   ||", 15);
            type_effect(" \\\\==================================================//", 15);
            cout << endl;

            // Detailed Box & Riddle Description
            type_effect("[ You pull the heavy wooden box closer to examine its surface ]", 45);
            cout << endl;
            type_effect("The box is made of a dense, dark timber, cold to the touch.", speed);
            type_effect("Your fingers trace a sharp, hand-carved riddle etched into the lid:", speed);

            cout << endl;
            type_effect("   +-----------------------------------------------------+", 15);
            type_effect("   |  \"I have no weight, yet I can hold the mightiest.  |", speed);
            type_effect("   |   I flow like water, yet I cannot be spilled.       |", speed);
            type_effect("   |   What is it that binds everything together         |", speed);
            type_effect("   |   in this world?\"                                   |", speed);
            type_effect("   +-----------------------------------------------------+", 15);
            cout << endl;

            type_effect("Below the inscription sits a mechanical brass dial mechanism.", speed);
            type_effect("It demands a 4-letter password to release the latch.", speed);
            cout << endl;
            gameState["wodenbox"] = true;
        }
        else if (gameState["wodenbox"] == true)
        {
            cout << endl;
            type_effect(" //==================================================\\\\", 15);
            type_effect("||                    THE WOODEN BOX                   ||", 15);
            type_effect(" \\\\==================================================//", 15);
            cout << endl;
        }

        cout << "What to do?\n1) enter_code (To enter the password)" << endl;
        cout << "2) back (To go back)\n3) hint (To read the hint agian)" << endl;
        cout << "Choice :";
        cin >> pass;
        if (pass == "enter_code")
        {
            cout << "ENTER THE CODE ;--,+=>>> ";
            cin >> code;
            cout << endl;
            if (code == "time")
            {
                box_open(gameState, way);
            }
            else
            {
                cout << "The box did not open. The password what can it be ?";
            }
        }
        else if (pass == "hint")
        {
            cout << endl;
            type_effect("   +-----------------------------------------------------+", 15);
            type_effect("   |  \"I have no weight, yet I can hold the mightiest.  |", speed);
            type_effect("   |   I flow like water, yet I cannot be spilled.       |", speed);
            type_effect("   |   What is it that binds everything together         |", speed);
            type_effect("   |   in this world?\"                                   |", speed);
            type_effect("   +-----------------------------------------------------+", 15);
            cout << endl;
        }

        else if (pass == "back")
        {
            break;
        }
        else if (pass == "pocket")
        {
            pocket(gameState);
        }
        else
        {
            cout << "<------ PLEASE INPUT A VALID INPUT ------>" << endl;
        }
    }
}

void box_open(map<string, bool> &gameState, string &way)
{
    if (gameState["hand"] == false)
    {
        int speed = 35;
        type_effect("\n[ CLICK! The lock springs open! ]", 50);

        type_effect("The heavy wooden lid lifts to reveal a plush velvet lining.", speed);
        type_effect("Resting inside is a solid, brass clock HOUR HAND.", speed);
        type_effect("It is beautifully crafted and looks like it belongs to a watch.", speed);

        cout << endl;
    }
    else if (gameState["hand"] == true)
    {
        cout << "THE BOX IS OPEN WHAT TO DO --->?";
    }
    while (true)
    {
        string hand;
        cout << "take_hand(To take the watch hand from the box)||(back)\n";
        cout << "Choice : ";
        cin >> hand;
        if (gameState["hand"] == false && hand == "take_hand")
        {
            type_effect("[ WATCH HOUR HAND ] added to inventory.", 35);
            gameState["hand"] = true;
        }
        else if (gameState["hand"] == true && hand == "take_hand")
        {
            type_effect("[ <___THE BOX IS EMPTY NOTHING TO ADD ___> ]", 35);
        }
        else if (hand == "pocket")
        {
            pocket(gameState);
        }
        else if (hand == "back")
        {
            break;
        }
        else
        {
            cout << "<------ PLEASE INPUT A VALID INPUT ------>" << endl;
        }
    }
}

void south_wall_intro(map<string, bool> &gameState, string &way)
{
    int speed = 35;

    cout << endl;
    type_effect(" //==================================================\\\\", 15);
    type_effect("||                     SOUTH WALL                      ||", 15);
    type_effect(" \\\\==================================================//", 15);
    cout << endl;
    type_effect("You turn around and face the SOUTH wall.", speed);
    type_effect("This side of the chamber feels remarkably clean and deliberate.", speed);

    cout << endl;

    type_effect("Mounted securely against the stone is a dark oak display shelf.", speed);
    type_effect("It is surprisingly pristine, as if untouched by the passage of time.", speed);

    cout << endl;

    // The Points of Interest (Box and Books)
    type_effect("Resting on the top shelf is a small, polished wooden box with a heavy iron lock.", speed);
    type_effect("Surrounding the box are rows of old, thick leather-bound books.", speed);

    cout << endl;

    type_effect("What would you like to do?", speed);
    cout << "1. inspect_shelf (Inspect the shelf)" << endl;
    cout << "2. inspect_box   (Inspect the wooden box)" << endl;
    cout << "3. back          (GO BACK)" << endl;
    cout << "4. open_pocket   (open the inventory)" << endl;
    cout << "5. turn          (To change direction)" << endl;
    cout << endl;
}

void south_wall_intro_north(map<string, bool> &gameState, string &way)
{
    int speed = 35;
    cout << endl;
    type_effect(" //==================================================\\\\", 15);
    type_effect("||                     SOUTH WALL                      ||", 15);
    type_effect(" \\\\==================================================//", 15);
    cout << endl;

    type_effect("You turn around and face the SOUTH wall.", speed);
    type_effect("This side of the chamber feels remarkably clean and deliberate.", speed);

    cout << endl;

    type_effect("Mounted securely against the stone is a dark oak display shelf.", speed);
    type_effect("It is surprisingly pristine, as if untouched by the passage of time.", speed);

    cout << endl;

    type_effect("Resting on the top shelf is a small, polished wooden box with a heavy iron lock.", speed);
    type_effect("Surrounding the box are rows of old, thick leather-bound books.", speed);
    type_effect("You glance at their faded spines—titles on ancient geometry and forgotten languages.", speed);
    type_effect("They look completely useless to your escape, serving only as a quiet frame for the box.", speed);

    cout << endl;

    type_effect("What would you like to do?", speed);
    cout << "1. inspect_shelf (Inspect the shelf)" << endl;
    cout << "2. inspect_box   (Inspect the wooden box)" << endl;
    cout << "3. back          (GO BACK)" << endl;
    cout << "4. open_pocket   (open the inventory)" << endl;
    cout << "5. turn          (To change direction)" << endl;
    cout << endl;
}

// <<--------------------------------------------------NORTH WALL-------------------------------------------->>

void north_wall_inspect(map<string, bool> &gameState, string &way)
{
    int speed = 35;
    cout << endl;
    type_effect("[ You step close and run your hands over the stone wall ]", 50);
    cout << endl;

    type_effect("The black rock is freezing to the touch, smooth as glass but impossibly dense.", speed);
    type_effect("Up close, the glowing geometric lines pulsed rhythmically, mirroring the room's low hum.", speed);
    type_effect("They look like map coordinates or mathematical constants tracking something unknown.", speed);

    cout << endl;

    type_effect("But the most peculiar thing about this view is the antique table.", speed);
    type_effect("It sits dead in the center, completely dominating this entire side of the chamber.", speed);
    type_effect("The dark wood stands in stark defiance of the cold stone walls around it.", speed);
    type_effect("It sits there heavy, silent, and breathing with purpose...", speed);
    type_effect("...as if it holds the secret, beating heart of this entire room.", 55);
    cout << endl;
}

void cover_letter()
{
    int speed = 35;

    cout << endl;
    type_effect("[ You pick up the crisp, yellowed parchment from the table ]", 60);
    cout << endl;
    cout << "     _______________________________________________ " << endl;
    cout << "    /                                               \\" << endl;
    cout << "   ||  +-----------------------------------------+  ||" << endl;
    cout << "   ||  |           --:Dear Ankit:--              |  ||" << endl;
    cout << "   ||  +-----------------------------------------+  ||" << endl;
    cout << "   ||                                               ||" << endl;
    cout << "   ||   \"When I woke up, my shadow was gone.        ||" << endl;
    cout << "   ||    That is when I really saw the glazing      ||" << endl;
    cout << "   ||    desert's mirage...\"                        ||" << endl;
    cout << "   ||                                               ||" << endl;
    cout << "   ||  -------------------------------------------  ||" << endl;
    cout << "   ||   From me to you, our footsteps alignment,    ||" << endl;
    cout << "   ||   Bound together in a silent assignment.      ||" << endl;
    cout << "   ||   We walk as twins, hand in hand,             ||" << endl;
    cout << "   ||   Marching forward through the sand.          ||" << endl;
    cout << "   ||   Should one falter, stumble, or break,       ||" << endl;
    cout << "   ||   The other walks on, for safety's sake.      ||" << endl;
    cout << "   ||  ___________________________________________  ||" << endl;
    cout << "   || /                                           \\ ||" << endl;
    cout << "   \\||_____________________________________________||/" << endl;
    cout << endl;
    type_effect("VOID :- The text is written in fading ink. The words seem heavily focused on a specific moment of the day.", speed);
    type_effect("PLAYER:- places the letter carefully back onto the antique wood.", speed);
    cout << endl;
    return;
}

void open_drawr(map<string, bool> &gameState, string &way)
{
    int speed = 35;
    string watch;

    if (gameState["watchinhand"] == false)
    {
        cout << endl;
        type_effect("[ You pull open the heavy wooden drawer ]", 50);

        type_effect("A scent of old copper and dust rises as the tracks groan.", speed);
        type_effect("Inside, a metallic gleam reveals a heavy, antique pocket watch resting on velvet.", speed);
        type_effect("The minute hand is frozen, but the hour hand is completely snapped off and missing.", speed);

        cout << endl;
        type_effect("Flipping it over, you see a sharp compass needle engraved on the back casing.", speed);
        type_effect("-> It points directly down, marked with a bold symbol of the SOUTH. <-", 55);
        cout << endl;

        while (true)
        {
            type_effect("What to do next? take_watch(To pick the watch up) | open_pocket | break .", 30);
            type_effect("\nChoice :", speed);
            cin >> watch;

            if (gameState["watchinhand"] == false && watch == "take_watch")
            {
                type_effect("[ BROKEN POCKET WATCH ] Has been stored in the pocket.", speed);
                gameState["watchinhand"] = true;
            }
            else if (gameState["watchinhand"] == true && watch == "take_watch")
            {
                type_effect("[ <-- EMPTY noting to add --> ] ", speed);
            }

            else if (watch == "break")
            {
                break;
            }

            else if (watch == "open_pocket")
            {
                pocket(gameState);
            }
            else
            {
                cout << "<------ PLEASE INPUT A VALID INPUT ------>" << endl;
            }
        }
    }
    else if (gameState["watchinhand"] == true)
    {
        cout << "\nThe drawer is open and empty." << endl;
    }
}

void table(map<string, bool> &gameState, string &way)
{

    int speed = 40;
    string choice;

    cout << endl;
    type_effect("[ You step closer to the antique table ]", 60);
    cout << endl;

    type_effect("Up close, the craftsmanship is remarkable.", speed);
    type_effect("The table is carved from a heavy, antique wood with a rich, dark grain.", speed);
    type_effect("Its polished surface reflects the faint glow of the room's geometric patterns.", speed);

    cout << endl;

    type_effect("Resting flat on the center of the dust-covered wood is an old cover letter.", speed);
    type_effect("Below it, you notice the top drawer is slightly open, pulled out just an inch.", speed);
    type_effect("Through the narrow crack, a small metallic object catches the light and shines brightly.", speed);

    cout << endl;

    while (true)
    {
        cout << endl;
        type_effect(" //==================================================\\\\", 15);
        type_effect("||                   THE ANTIQUE TABLE                 ||", 15);
        type_effect(" \\\\==================================================//", 15);
        cout << endl;
        type_effect("What would you like to do?", speed);
        cout << "1. cover_letter (Inspect the cover letter)" << endl;
        cout << "2. open_drawr   (Inspect the drawer)" << endl;
        cout << "3. back (To reterun back to the previous window)" << endl;
        cout << "4. open_pocket (To open the inventory )" << endl;
        cout << endl;

        cout << "Choice :";
        cin >> choice;
        if (choice == "cover_letter")
        {
            cover_letter();
            type_effect("What next? (Type: cover_letter / open_drawr / back/open_pocket)", 30);
        }
        else if (choice == "open_drawr")
        {
            open_drawr(gameState, way);
        }
        else if (choice == "back")
        {
            break;
        }
        else if (choice == "open_pocket")
        {
            pocket(gameState);
        }
        else
        {
            cout << "<------ PLEASE INPUT A VALID INPUT ------>" << endl;
        }
    }
}

void north_wall_intro(map<string, bool> &gameState, string &way)
{
    int speed = 40;
    cout << endl;
    type_effect(" //==================================================\\\\", 15);
    type_effect("||                      NORTH WALL                     ||", 15);
    type_effect(" \\\\==================================================//", 15);
    cout << endl;
    type_effect("[ You turn to face the NORTH wall ]", 60);
    cout << endl;

    type_effect("You look ahead at a towering slab of polished black stone.", speed);
    type_effect("Faint geometric patterns are etched across the surface, glowing softly in the dark.", speed);

    cout << endl;

    type_effect("Positioned right against the center of the wall is an antique wooden TABLE.", speed);
    type_effect("Its surface is dark, weathered, and covered in deep scratches from years of use.", speed);
    type_effect("Built into the front of the table, you notice a set of heavy wooden DRAWRS.", speed);
    type_effect("They are closed tight, waiting to be OPENED.", speed);
    cout << endl;
    type_effect("VOID :- What will you do next?", 45);
    cout << "--------------------------------------------------------" << endl;

    type_effect("table        -=- (To inspect the table)", 20);
    type_effect("wall_inspect -=- (To inspect the wall in detail)", 20);
    type_effect("wall_intro   -=- (To listen to the wall introduction)", 20);
    type_effect("open_pocket  -=- (To open your inventory)", 20);
    type_effect("turn         -=- (To change direction )", 20);

    cout << "--------------------------------------------------------" << endl;
    cout << endl;
}

// <<--------------------------------------------------MAIN JUCTION-------------------------------------------->>

void directions(string &way, map<string, void (*)(map<string, bool> &, string &)> &v, map<string, bool> &gameState)
{
    v["north"] = north_wall;
    v["south"] = south_wall;
    v["west"] = west_wall;
    v["east"] = east_wall;
    while (true)
    {
        if (way.empty())
        {
            type_effect("VOID :- Which direction would you like to GO-->? (Type: NORTH, EAST, SOUTH, or WEST)", 50);
            cout << "Choice : ";
            cin >> way;
        }
        else if (v.count(way) > 0)
        {
            v[way](gameState, way);
            way = "";
        }
        else
        {
            cout << "<------ PLEASE INPUT A VALID INPUT ------>" << endl;
            way = "";
        }
    }
}

// <<--------------------------------------------------MAIN-------------------------------------------->>

int main()
{
    string way = "";
    map<string, void (*)(map<string, bool> &, string &)> val1;
    map<string, bool> gameState;
    gameState["northVisited"] = false;
    gameState["southVisited"] = false;
    gameState["eastVisited"] = false;
    gameState["westVisited"] = false;
    gameState["watchinhand"] = false;
    gameState["wodenbox"] = false;
    gameState["hand"] = false;
    gameState["shelfvisit"] = false;
    gameState["timecode"] = false;
    gameState["digitalcode"] = false;

    intro();
    directions(way, val1, gameState);

    return 0;}

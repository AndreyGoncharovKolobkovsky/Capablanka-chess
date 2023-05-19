#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

struct Position{
    int x, y;
};

class Piece{
public:
    Position position;
    bool ifTouching = false;
    int colour;
    virtual bool move_is_available(vector<vector<int>>& playing_board_situation) = 0;

};

class Pawn_b: public Piece{
public:
    Pawn_b(Position start){
        position = start;
        cout << position.x * 100 << " " << position.y * 100 << endl;
        colour = -1;
    }
    bool move_is_available(vector<vector<int>>& playing_board_situation) override{

    };
};
class Pawn_w: public Piece{
public:
    Pawn_w(Position start){
        position = start;
        cout << position.x * 100 << " " << position.y * 100 << endl;
        colour = 1;
    }
    bool move_is_available(vector<vector<int>>& playing_board_situation) override{

    };
};
class Bishop: public Piece{
public:
    Bishop(Position start, int colour){
        position = start;
        cout << position.x * 100 << " " << position.y * 100 << endl;
        this->colour = colour;
    }
    bool move_is_available(vector<vector<int>>& playing_board_situation) override{
    };
};
class Rook: public Piece{
public:
    Rook(Position start, int colour){
        position = start;
        cout << position.x * 100 << " " << position.y * 100 << endl;
        this->colour = colour;
    }
    bool move_is_available(vector<vector<int>>& playing_board_situation) override{
    };
};
class Knight: public Piece{
public:
    Knight(Position start, int colour){
        position = start;
        cout << position.x * 100 << " " << position.y * 100 << endl;
        this->colour = colour;
    }
    bool move_is_available(vector<vector<int>>& playing_board_situation) override{

    };
};
class Chancellor: public Piece{
public:
    Chancellor(Position start, int colour){
        position = start;
        cout << position.x * 100 << " " << position.y * 100 << endl;
        this->colour = colour;
    }
    bool move_is_available(vector<vector<int>>& playing_board_situation) override{

    };
};
class Archbishop: public Piece{
public:
    Archbishop(Position start, int colour){
        position = start;
        cout << position.x * 100 << " " << position.y * 100 << endl;
        this->colour = colour;
    }
    bool move_is_available(vector<vector<int>>& playing_board_situation) override{

    };
};
class Queen: public Piece{
public:
    Queen(Position start, int colour){
        position = start;
        cout << position.x * 100 << " " << position.y * 100 << endl;
        this->colour = colour;
    }
    bool move_is_available(vector<vector<int>>& playing_board_situation) override{

    };
};
class King: public Piece{
public:
    King(Position start, int colour){
        position = start;
        cout << position.x * 100 << " " << position.y * 100 << endl;
        this->colour = colour;
    }
    bool move_is_available(vector<vector<int>>& playing_board_situation) override{

    };
};

int main(){
    RenderWindow window(VideoMode(  1000, 800), "Capablanka Chess");
    //Создание игровой зоны
#pragma region Play_Area_definition
    vector <vector <RectangleShape>> PlayingZone(10, vector <RectangleShape> (8));
    vector<vector<int>> playing_board_situation(10, vector<int>(8));
    playing_board_situation[0] = {-5, -1, 0, 0, 0, 0, 1, 5};
    playing_board_situation[1] = {-4, -1, 0, 0, 0, 0, 1, 4};
    playing_board_situation[2] = {-8, -1, 0, 0, 0, 0, 1, 8};
    playing_board_situation[3] = {-3, -1, 0, 0, 0, 0, 1, 3};
    playing_board_situation[4] = {-6, -1, 0, 0, 0, 0, 1, 6};
    playing_board_situation[5] = {-2, -1, 0, 0, 0, 0, 1, 2};
    playing_board_situation[6] = {-3, -1, 0, 0, 0, 0, 1, 3};
    playing_board_situation[7] = {-7, -1, 0, 0, 0, 0, 1, 7};
    playing_board_situation[8] = {-4, -1, 0, 0, 0, 0, 1, 4};
    playing_board_situation[9] = {-5, -1, 0, 0, 0, 0, 1, 5};
    //создание игрового поля
    for(int i = 0; i < 10; i ++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                PlayingZone[i][j] = sf::RectangleShape(sf::Vector2f(100, 100));
                PlayingZone[i][j].setFillColor(sf::Color(247, 208, 164));
                PlayingZone[i][j].setPosition(100 * i, 100 * j);
            } else {
                PlayingZone[i][j] = sf::RectangleShape(sf::Vector2f(100, 100));
                PlayingZone[i][j].setFillColor(sf::Color(200, 143, 82));
                PlayingZone[i][j].setPosition(100 * i, 100 * j);
            }
        }
    }
    Font font;
    font.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/arialmt.ttf");
    vector<Text> vertical_text(8);
    vector<Text> horizontal_text(10);
    for(int i = 0; i < 8; i++){
        string f = to_string(8-i);
        Text text("",font, 25);
        vertical_text[i] = text;
        vertical_text[i].setPosition(0, (i)*100);
        vertical_text[i].setStyle(sf::Text::Bold);
        vertical_text[i].setString(f);
        if(i%2 == 0) vertical_text[i].setColor(Color(200, 143, 82));
        else vertical_text[i].setColor(Color(247, 208, 164));
    }
    char l_counter = 'a';
    for(int i = 0; i < 10; i++){
        Text text("",font, 25);
        horizontal_text[i] = text;
        horizontal_text[i].setPosition((i+1)*100-14, 770);
        horizontal_text[i].setStyle(sf::Text::Bold);
        horizontal_text[i].setString(l_counter);
        if(i%2 == 0) horizontal_text[i].setColor(Color(247, 208, 164));
        else horizontal_text[i].setColor(Color(200, 143, 82));
        l_counter ++;
    }
    vector<RectangleShape> Chess(40);
#pragma endregion
    //Создание фигур
#pragma region spawn_pieces
    Texture texture;
    Image pawn_b_img, pawn_w_img, bishop_b_img, bishop_w_img, rook_b_img, rook_w_img, knight_b_img, knight_w_img, chancellor_b_img, chancellor_w_img, archbishop_b_img, archbishop_w_img, queen_b_img, queen_w_img, king_b_img, king_w_img;
    Texture pawn_b_tx, pawn_w_tx, bishop_b_tx, bishop_w_tx, rook_b_tx, rook_w_tx, knight_b_tx, knight_w_tx, chancellor_b_tx, chancellor_w_tx, archbishop_b_tx, archbishop_w_tx, queen_b_tx, queen_w_tx, king_b_tx, king_w_tx;
    Sprite pawn_b_sp, pawn_w_sp, bishop_b_sp, bishop_w_sp, rook_b_sp, rook_w_sp, knight_b_sp, knight_w_sp, chancellor_b_sp, chancellor_w_sp, archbishop_b_sp, archbishop_w_sp, queen_b_sp, queen_w_sp, king_b_sp, king_w_sp;
    pawn_w_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/pawn_w.png");
    pawn_w_tx.loadFromImage(pawn_w_img);
    pawn_w_sp.setTexture(pawn_w_tx);
    vector<pair<Pawn_w, Sprite>> white_pawns;
    for(int i = 0; i < 10; i++){
        Pawn_w tmp({i, 6});
        pair<Pawn_w, Sprite> tmp_ = {tmp, pawn_w_sp};
        tmp_.second.setPosition(i*100, 600);
        white_pawns.push_back(tmp_);
    }
    pawn_b_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/pawn_b.png");
    pawn_b_tx.loadFromImage(pawn_b_img);
    pawn_b_sp.setTexture(pawn_b_tx);
    vector<pair<Pawn_b, Sprite>> black_pawns;
    for(int i = 0; i < 10; i++){
        Pawn_b tmp({i, 1});
        pair<Pawn_b, Sprite> tmp_ = {tmp, pawn_b_sp};
        tmp_.second.setPosition(i*100, 100);
        black_pawns.push_back(tmp_);
    }
    bishop_b_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/bishop_b.png");
    bishop_w_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/bishop_w.png");
    bishop_b_tx.loadFromImage(bishop_b_img);
    bishop_w_tx.loadFromImage(bishop_w_img);
    bishop_b_sp.setTexture(bishop_b_tx);
    bishop_w_sp.setTexture(bishop_w_tx);
    vector<pair<Bishop, Sprite>> bishop;
    vector<Position> start = {{3, 0}, {3, 7}, {6, 0}, {6, 7}};
    for(int i = 0; i < 4; i++){
        if(i%2 == 0){
            Bishop tmp(start[i], -1);
            pair<Bishop, Sprite> tmp_ = {tmp, bishop_b_sp};
            tmp_.second.setPosition(start[i].x*100, start[i].y*100);
            bishop.push_back(tmp_);
        }else{
            Bishop tmp(start[i], 1);
            pair<Bishop, Sprite> tmp_ = {tmp, bishop_w_sp};
            tmp_.second.setPosition(start[i].x*100, start[i].y*100);
            bishop.push_back(tmp_);
        }
    }
    rook_b_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/rook_b.png");
    rook_w_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/rook_w.png");
    rook_b_tx.loadFromImage(rook_b_img);
    rook_w_tx.loadFromImage(rook_w_img);
    rook_b_sp.setTexture(rook_b_tx);
    rook_w_sp.setTexture(rook_w_tx);
    vector<pair<Rook, Sprite>> rook;
    start = {{0, 0}, {0, 7}, {9, 0}, {9, 7}};
    for(int i = 0; i < 4; i++){
        if(i%2 == 0){
            Rook tmp(start[i], -1);
            pair<Rook, Sprite> tmp_ = {tmp, rook_b_sp};
            tmp_.second.setPosition(start[i].x*100, start[i].y*100);
            rook.push_back(tmp_);
        }else{
            Rook tmp(start[i], 1);
            pair<Rook, Sprite> tmp_ = {tmp, rook_w_sp};
            tmp_.second.setPosition(start[i].x*100, start[i].y*100);
            rook.push_back(tmp_);
        }
    }
    knight_b_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/knight_b.png");
    knight_w_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/knight_w.png");
    knight_b_tx.loadFromImage(knight_b_img);
    knight_w_tx.loadFromImage(knight_w_img);
    knight_b_sp.setTexture(knight_b_tx);
    knight_w_sp.setTexture(knight_w_tx);
    vector<pair<Knight, Sprite>> knight;
    start = {{1, 0}, {1, 7}, {8, 0}, {8, 7}};
    for(int i = 0; i < 4; i++){
        if(i%2 == 0){
            Knight tmp(start[i], -1);
            pair<Knight, Sprite> tmp_ = {tmp, knight_b_sp};
            tmp_.second.setPosition(start[i].x*100, start[i].y*100);
            knight.push_back(tmp_);
        }else{
            Knight tmp(start[i], 1);
            pair<Knight, Sprite> tmp_ = {tmp, knight_w_sp};
            tmp_.second.setPosition(start[i].x*100, start[i].y*100);
            knight.push_back(tmp_);
        }
    }
    chancellor_b_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/chancellor_b.png");
    chancellor_w_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/chancellor_w.png");
    chancellor_b_tx.loadFromImage(chancellor_b_img);
    chancellor_w_tx.loadFromImage(chancellor_w_img);
    chancellor_b_sp.setTexture(chancellor_b_tx);
    chancellor_w_sp.setTexture(chancellor_w_tx);
    vector<pair<Chancellor, Sprite>> chancellor;
    for(int i = 0; i < 2; i++){
        if(i%2 == 0){
            Chancellor tmp({2, 0}, -1);
            pair<Chancellor, Sprite> tmp_ = {tmp, chancellor_b_sp};
            tmp_.second.setPosition(200, 000);
            chancellor.push_back(tmp_);
        }else{
            Chancellor tmp({2, 7} , 1);
            pair<Chancellor, Sprite> tmp_ = {tmp, chancellor_w_sp};
            tmp_.second.setPosition(200, 700);
            chancellor.push_back(tmp_);
        }
    }
    archbishop_b_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/archbishop_b.png");
    archbishop_w_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/archbishop_w.png");
    archbishop_b_tx.loadFromImage(archbishop_b_img);
    archbishop_w_tx.loadFromImage(archbishop_w_img);
    archbishop_b_sp.setTexture(archbishop_b_tx);
    archbishop_w_sp.setTexture(archbishop_w_tx);
    vector<pair<Archbishop, Sprite>> archbishop;
    for(int i = 0; i < 2; i++){
        if(i%2 == 0){
            Archbishop tmp({7, 0}, -1);
            pair<Archbishop, Sprite> tmp_ = {tmp, archbishop_b_sp};
            tmp_.second.setPosition(700, 000);
            archbishop.push_back(tmp_);
        }else{
            Archbishop tmp({7, 7}, 1);
            pair<Archbishop, Sprite> tmp_ = {tmp, archbishop_w_sp};
            tmp_.second.setPosition(700, 700);
            archbishop.push_back(tmp_);
        }
    }
    queen_b_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/queen_b.png");
    queen_w_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/queen_w.png");
    queen_b_tx.loadFromImage(queen_b_img);
    queen_w_tx.loadFromImage(queen_w_img);
    queen_b_sp.setTexture(queen_b_tx);
    queen_w_sp.setTexture(queen_w_tx);
    vector<pair<Queen, Sprite>> queen;
    for(int i = 0; i < 2; i++){
        if(i%2 == 0){
            Queen tmp({4, 0}, -1);
            pair<Queen, Sprite> tmp_ = {tmp, queen_b_sp};
            tmp_.second.setPosition(400, 000);
            queen.push_back(tmp_);
        }else{
            Queen tmp({4, 7}, 1);
            pair<Queen, Sprite> tmp_ = {tmp, queen_w_sp};
            tmp_.second.setPosition(400, 700);
            queen.push_back(tmp_);
        }
    }
    king_b_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/king_b.png");
    king_w_img.loadFromFile("C:/Users/gonch/CLionProjects/ForSFML/images/king_w.png");
    king_b_tx.loadFromImage(king_b_img);
    king_w_tx.loadFromImage(king_w_img);
    king_b_sp.setTexture(king_b_tx);
    king_w_sp.setTexture(king_w_tx);
    vector<pair<King, Sprite>> king;
    for(int i = 0; i < 2; i++){
        if(i%2 == 0){
            King tmp(start[i], -1);
            pair<King, Sprite> tmp_ = {tmp, king_b_sp};
            tmp_.second.setPosition(500, 000);
            king.push_back(tmp_);
        }else{
            King tmp(start[i], 1);
            pair<King, Sprite> tmp_ = {tmp, king_w_sp};
            tmp_.second.setPosition(500, 700);
            king.push_back(tmp_);
        }
    }
#pragma endregion
    Event event;
    vector<bool> is_pressed_pawn_b(10, false);
    vector<bool> is_pressed_pawn_w(10, false);
    vector<bool> is_pressed_bishop(4, false);
    vector<bool> is_pressed_knight(4, false);
    vector<bool> is_pressed_rook(4, false);
    vector<bool> is_pressed_queen(2, false);
    vector<bool> is_pressed_king(2, false);
    vector<bool> is_pressed_archbishop(2, false);
    vector<bool> is_pressed_chancellor(2, false);
    while(window.isOpen()){
        Vector2i mouse_position = Mouse::getPosition(window);
        while(window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
            for(unsigned int i = 0; i < black_pawns.size(); i++){
                if (event.type == Event::MouseButtonPressed){
                    if (event.key.code == Mouse::Left){
                        if (black_pawns[i].second.getGlobalBounds().contains(mouse_position.x, mouse_position.y)){
                            is_pressed_pawn_b[i] = true;
                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased){
                    if (event.key.code == Mouse::Left){
                        is_pressed_pawn_b[i] = false;
                        Vector2f pos_tmp;
                        if((int)(black_pawns[i].second.getPosition().x) % 100 > 50) pos_tmp.x = (int)((black_pawns[i].second.getPosition().x+100)/100)*100;
                        else pos_tmp.x = (int)((black_pawns[i].second.getPosition().x)/100)*100;
                        if((int)(black_pawns[i].second.getPosition().y) % 100 > 50) pos_tmp.y = (int)((black_pawns[i].second.getPosition().y+100)/100)*100;
                        else pos_tmp.y = (int)((black_pawns[i].second.getPosition().y)/100)*100;
                        black_pawns[i].second.setPosition(pos_tmp);
                    }
                }
            }
            for(unsigned int i = 0; i < white_pawns.size(); i++){
                if (event.type == Event::MouseButtonPressed){
                    if (event.key.code == Mouse::Left){
                        if (white_pawns[i].second.getGlobalBounds().contains(mouse_position.x, mouse_position.y)){
                            is_pressed_pawn_w[i] = true;
                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased){
                    if (event.key.code == Mouse::Left){
                        is_pressed_pawn_w[i] = false;
                        Vector2f pos_tmp;
                        if((int)(white_pawns[i].second.getPosition().x) % 100 > 50) pos_tmp.x = (int)((white_pawns[i].second.getPosition().x+100)/100)*100;
                        else pos_tmp.x = (int)((white_pawns[i].second.getPosition().x)/100)*100;
                        if((int)(white_pawns[i].second.getPosition().y) % 100 > 50) pos_tmp.y = (int)((white_pawns[i].second.getPosition().y+100)/100)*100;
                        else pos_tmp.y = (int)((white_pawns[i].second.getPosition().y)/100)*100;
                        white_pawns[i].second.setPosition(pos_tmp);
                    }
                }
            }
            for(unsigned int i = 0; i < bishop.size(); i++){
                if (event.type == Event::MouseButtonPressed){
                    if (event.key.code == Mouse::Left){
                        if (bishop[i].second.getGlobalBounds().contains(mouse_position.x, mouse_position.y)){

                            is_pressed_bishop[i] = true;
                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased){
                    if (event.key.code == Mouse::Left){
                        is_pressed_bishop[i] = false;
                        Vector2f pos_tmp;
                        if((int)(bishop[i].second.getPosition().x) % 100 > 50) pos_tmp.x = (int)((bishop[i].second.getPosition().x+100)/100)*100;
                        else pos_tmp.x = (int)((bishop[i].second.getPosition().x)/100)*100;
                        if((int)(bishop[i].second.getPosition().y) % 100 > 50) pos_tmp.y = (int)((bishop[i].second.getPosition().y+100)/100)*100;
                        else pos_tmp.y = (int)((bishop[i].second.getPosition().y)/100)*100;
                        bishop[i].second.setPosition(pos_tmp);
                    }
                }
            }
            for(unsigned int i = 0; i < knight.size(); i++){
                if (event.type == Event::MouseButtonPressed){
                    if (event.key.code == Mouse::Left){
                        if (knight[i].second.getGlobalBounds().contains(mouse_position.x, mouse_position.y)){
                            is_pressed_knight[i] = true;
                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased){
                    if (event.key.code == Mouse::Left){
                        is_pressed_knight[i] = false;
                        Vector2f pos_tmp;
                        if((int)(knight[i].second.getPosition().x) % 100 > 50) pos_tmp.x = (int)((knight[i].second.getPosition().x+100)/100)*100;
                        else pos_tmp.x = (int)((knight[i].second.getPosition().x)/100)*100;
                        if((int)(knight[i].second.getPosition().y) % 100 > 50) pos_tmp.y = (int)((knight[i].second.getPosition().y+100)/100)*100;
                        else pos_tmp.y = (int)((knight[i].second.getPosition().y)/100)*100;
                        knight[i].second.setPosition(pos_tmp);
                    }
                }
            }
            for(unsigned int i = 0; i < rook.size(); i++){
                if (event.type == Event::MouseButtonPressed){
                    if (event.key.code == Mouse::Left){
                        if (rook[i].second.getGlobalBounds().contains(mouse_position.x, mouse_position.y)){
                            is_pressed_rook[i] = true;
                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased){
                    if (event.key.code == Mouse::Left){
                        is_pressed_rook[i] = false;
                        Vector2f pos_tmp;
                        if((int)(rook[i].second.getPosition().x) % 100 > 50) pos_tmp.x = (int)((rook[i].second.getPosition().x+100)/100)*100;
                        else pos_tmp.x = (int)((rook[i].second.getPosition().x)/100)*100;
                        if((int)(rook[i].second.getPosition().y) % 100 > 50) pos_tmp.y = (int)((rook[i].second.getPosition().y+100)/100)*100;
                        else pos_tmp.y = (int)((rook[i].second.getPosition().y)/100)*100;
                        rook[i].second.setPosition(pos_tmp);
                    }
                }
            }
            for(unsigned int i = 0; i < queen.size(); i++){
                if (event.type == Event::MouseButtonPressed){
                    if (event.key.code == Mouse::Left){
                        if (queen[i].second.getGlobalBounds().contains(mouse_position.x, mouse_position.y)){
                            is_pressed_queen[i] = true;
                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased){
                    if (event.key.code == Mouse::Left){
                        is_pressed_queen[i] = false;
                        Vector2f pos_tmp;
                        if((int)(queen[i].second.getPosition().x) % 100 > 50) pos_tmp.x = (int)((queen[i].second.getPosition().x+100)/100)*100;
                        else pos_tmp.x = (int)((queen[i].second.getPosition().x)/100)*100;
                        if((int)(queen[i].second.getPosition().y) % 100 > 50) pos_tmp.y = (int)((queen[i].second.getPosition().y+100)/100)*100;
                        else pos_tmp.y = (int)((queen[i].second.getPosition().y)/100)*100;
                        queen[i].second.setPosition(pos_tmp);
                    }
                }
            }
            for(unsigned int i = 0; i < king.size(); i++){
                if (event.type == Event::MouseButtonPressed){
                    if (event.key.code == Mouse::Left){
                        if (king[i].second.getGlobalBounds().contains(mouse_position.x, mouse_position.y)){
                            is_pressed_king[i] = true;
                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased){
                    if (event.key.code == Mouse::Left){
                        is_pressed_king[i] = false;
                        Vector2f pos_tmp;
                        if((int)(king[i].second.getPosition().x) % 100 > 50) pos_tmp.x = (int)((king[i].second.getPosition().x+100)/100)*100;
                        else pos_tmp.x = (int)((king[i].second.getPosition().x)/100)*100;
                        if((int)(king[i].second.getPosition().y) % 100 > 50) pos_tmp.y = (int)((king[i].second.getPosition().y+100)/100)*100;
                        else pos_tmp.y = (int)((king[i].second.getPosition().y)/100)*100;
                        king[i].second.setPosition(pos_tmp);
                    }
                }
            }
            for(unsigned int i = 0; i < archbishop.size(); i++){
                if (event.type == Event::MouseButtonPressed){
                    if (event.key.code == Mouse::Left){
                        if (archbishop[i].second.getGlobalBounds().contains(mouse_position.x, mouse_position.y)){
                            is_pressed_archbishop[i] = true;
                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased){
                    if (event.key.code == Mouse::Left){
                        is_pressed_archbishop[i] = false;
                        Vector2f pos_tmp;
                        if((int)(archbishop[i].second.getPosition().x) % 100 > 50) pos_tmp.x = (int)((archbishop[i].second.getPosition().x+100)/100)*100;
                        else pos_tmp.x = (int)((archbishop[i].second.getPosition().x)/100)*100;
                        if((int)(archbishop[i].second.getPosition().y) % 100 > 50) pos_tmp.y = (int)((archbishop[i].second.getPosition().y+100)/100)*100;
                        else pos_tmp.y = (int)((archbishop[i].second.getPosition().y)/100)*100;
                        archbishop[i].second.setPosition(pos_tmp);
                    }
                }
            }
            for(unsigned int i = 0; i < chancellor.size(); i++){
                if (event.type == Event::MouseButtonPressed){
                    if (event.key.code == Mouse::Left){
                        if (chancellor[i].second.getGlobalBounds().contains(mouse_position.x, mouse_position.y)){
                            is_pressed_chancellor[i] = true;
                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased){
                    if (event.key.code == Mouse::Left){
                        is_pressed_chancellor[i] = false;
                        Vector2f pos_tmp;
                        if((int)(chancellor[i].second.getPosition().x) % 100 > 50) pos_tmp.x = (int)((chancellor[i].second.getPosition().x+100)/100)*100;
                        else pos_tmp.x = (int)((chancellor[i].second.getPosition().x)/100)*100;
                        if((int)(chancellor[i].second.getPosition().y) % 100 > 50) pos_tmp.y = (int)((chancellor[i].second.getPosition().y+100)/100)*100;
                        else pos_tmp.y = (int)((chancellor[i].second.getPosition().y)/100)*100;
                        chancellor[i].second.setPosition(pos_tmp);
                        cout << chancellor[i].first.position.x << " " << chancellor[i].first.position.y << endl;
                        playing_board_situation[chancellor[i].first.position.x][chancellor[i].first.position.y] = 0;
                        chancellor[i].first.position = {int(pos_tmp.x)/100, int(pos_tmp.y)/100};
                        playing_board_situation[int(pos_tmp.x)/100][int(pos_tmp.y)/100] = chancellor[i].first.colour*8;
                        
                        for(unsigned int k = 0; k < playing_board_situation.size(); k++){
                            for(unsigned int u = 0; u < playing_board_situation[k].size(); u++) cout << playing_board_situation[k][u] << " ";
                            cout << endl;
                        } cout << endl << endl;
                    }
                }
            }
        }
        for(unsigned int i = 0; i < black_pawns.size(); i++){
            if (Mouse::isButtonPressed(Mouse::Left)){
                if (is_pressed_pawn_b[i]){
                    black_pawns[i].second.setPosition(mouse_position.x-50, mouse_position.y-50);
                }
            }
        }
        for(unsigned int i = 0; i < white_pawns.size(); i++){
            if (Mouse::isButtonPressed(Mouse::Left)){
                if (is_pressed_pawn_w[i]){
                    white_pawns[i].second.setPosition(mouse_position.x-50, mouse_position.y-50);
                }
            }
        }
        for(unsigned int i = 0; i < is_pressed_bishop.size(); i++){
            if (Mouse::isButtonPressed(Mouse::Left)){
                if (is_pressed_bishop[i]){
                    bishop[i].second.setPosition(mouse_position.x-50, mouse_position.y-50);
                }
            }
        }
        for(unsigned int i = 0; i < is_pressed_knight.size(); i++){
            if (Mouse::isButtonPressed(Mouse::Left)){
                if (is_pressed_knight[i]){
                    knight[i].second.setPosition(mouse_position.x-50, mouse_position.y-50);
                }
            }
        }
        for(unsigned int i = 0; i < is_pressed_rook.size(); i++){
            if (Mouse::isButtonPressed(Mouse::Left)){
                if (is_pressed_rook[i]){
                    rook[i].second.setPosition(mouse_position.x-50, mouse_position.y-50);
                }
            }
        }
        for(unsigned int i = 0; i < is_pressed_queen.size(); i++){
            if (Mouse::isButtonPressed(Mouse::Left)){
                if (is_pressed_queen[i]){
                    queen[i].second.setPosition(mouse_position.x-50, mouse_position.y-50);
                }
            }
        }
        for(unsigned int i = 0; i < is_pressed_king.size(); i++){
            if (Mouse::isButtonPressed(Mouse::Left)){
                if (is_pressed_king[i]){
                    king[i].second.setPosition(mouse_position.x-50, mouse_position.y-50);
                }
            }
        }
        for(unsigned int i = 0; i < is_pressed_archbishop.size(); i++){
            if (Mouse::isButtonPressed(Mouse::Left)){
                if (is_pressed_archbishop[i]){
                    archbishop[i].second.setPosition(mouse_position.x-50, mouse_position.y-50);
                }
            }
        }
        for(unsigned int i = 0; i < is_pressed_chancellor.size(); i++){
            if (Mouse::isButtonPressed(Mouse::Left)){
                if (is_pressed_chancellor[i]){
                    chancellor[i].second.setPosition(mouse_position.x-50, mouse_position.y-50);
                }
            }
        }

        window.clear();
        for(int i = 0; i < 10; i ++) {
            for (int j = 0; j < 8; j++) {
                window.draw(PlayingZone[i][j]);
            }
        }
        for(int i = 0; i < 8; i ++) window.draw(vertical_text[i]);
        for(int i = 0; i < 10; i ++) window.draw(horizontal_text[i]);
        for(unsigned int i = 0; i < black_pawns.size(); i ++) window.draw(black_pawns[i].second);
        for(unsigned int i = 0; i < black_pawns.size(); i ++) window.draw(white_pawns[i].second);
        for(unsigned int i = 0; i < rook.size(); i ++) window.draw(rook[i].second);
        for(unsigned int i = 0; i < bishop.size(); i ++) window.draw(bishop[i].second);
        for(unsigned int i = 0; i < knight.size(); i ++) window.draw(knight[i].second);
        for(unsigned int i = 0; i < chancellor.size(); i ++) window.draw(chancellor[i].second);
        for(unsigned int i = 0; i < archbishop.size(); i ++) window.draw(archbishop[i].second);
        for(unsigned int i = 0; i < queen.size(); i ++) window.draw(queen[i].second);
        for(unsigned int i = 0; i < king.size(); i ++) window.draw(king[i].second);
        window.display();
    }
    return 0;
}
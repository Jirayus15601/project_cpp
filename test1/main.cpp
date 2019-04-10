#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace sf;
using namespace std;

constexpr double pi() { return atan(1)*4; }

int main()
{
    const unsigned int s = 1600;
    const unsigned int N = 900;

    RenderWindow window(VideoMode(s, N),"Graph");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(100);

    
    int data;
    cout<<"Enter number of data : ";
    cin>>data;

    float Y[data+1]={};
    Y[0] = 0;
    for (int i=1;i<data+1;i++){
        cout<<"Enter data["<<i<<"] : ";
        cin>>Y[i];
    }
    float Ymax =Y[0];
    for(int i=1;i<data+1;i++){
        if(Y[i]>Ymax) Ymax = Y[i];
    }
    VertexArray graph(LinesStrip,3);
    graph[0].position = Vector2f(100,50);
    graph[1].position = Vector2f(100,800);
    graph[2].position = Vector2f(1550,800);

    VertexArray chart(LinesStrip,data+1);
    for (int i=0;i<data+1;i++){
        unsigned int x = (i*(1400/data))+100;
        unsigned int y = 800-(700/Ymax)*Y[i];
        chart[i].position = Vector2f(x,y);
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed) window.close();


        window.draw(graph);

        window.draw(chart);

        window.display();
    }
    return 0;
}

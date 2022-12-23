#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <stack>
#include <queue>
#include <map>
#include <conio.h>
using namespace std;
struct node
{
    string data;
    map<string, int> edge;
};

struct dijkstrahelp {
    int totalcost;
    bool visited;
    string lastnode;
};

class graph
{
    vector<node> vec;
    string closestnode(map<string, dijkstrahelp> m)
    {
        string close = "";
        for (auto i : m)
        {
            if (!i.second.visited && (close == "" || i.second.totalcost < m[close].totalcost))
                close = i.first;
        }
        return close;
    }
    void printpath(map<string, dijkstrahelp> m, string a, string b)
    {
        string curr = b;

        while (curr != "")
        {
            string last = m[curr].lastnode;
            int dist = m[curr].totalcost - m[last].totalcost;
            cout << curr << " " << dist << endl;
            curr = last;
        }
    }
public:
    int search_vertex(string data)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].data == data)
                return i;
        }
        return -1;
    }

    void insert_vertex(string data)
    {
        if (search_vertex(data) != -1)
        {
            cout << "Vertex already exist!!";
            return;
        }
        node temp;
        temp.data = data;
        vec.push_back(temp);
    }

    void insert_edge(string a, string b, int dist)
    {
        int vertexa = search_vertex(a);
        int vertexb = search_vertex(b);
        if (vertexa == -1 || vertexb == -1)
        {
            cout << "Invalid vertices for inserting!";
            return;
        }
        vec[vertexa].edge[b] = dist;

        vec[vertexb].edge[a] = dist;
    }

    void dijkstra(string a, string b)
    {
        map<string, dijkstrahelp> m;

        for (int i = 0; i < vec.size(); i++)
        {
            m[vec[i].data].totalcost = INT_MAX;
            m[vec[i].data].visited = false;
        }

        m[a].totalcost = 0;
        m[a].lastnode = "";
        for (int i = 0; i < vec.size(); i++)
        {
            string newnode = closestnode(m);
            int newnodeindex = search_vertex(newnode);
            for (auto j : vec[newnodeindex].edge)
            {
                if (m[j.first].totalcost > m[newnode].totalcost + vec[newnodeindex].edge[j.first])
                {
                    m[j.first].totalcost = m[newnode].totalcost + vec[newnodeindex].edge[j.first];
                    m[j.first].lastnode = newnode;
                }
            }
            m[newnode].visited = true;
        }
        printpath(m, a, b);
    }
};

graph karachigraph()
{
    graph g;
    g.insert_vertex("Bhens Colony");
    g.insert_vertex("Machar Colony");
    g.insert_vertex("Kati Pahaari");
    g.insert_vertex("Soldier Bazar");
    g.insert_vertex("Teen Talwaar");
    g.insert_vertex("Mazar e Quaid");
    g.insert_vertex("Layaari");
    g.insert_vertex("Burns Road");
    g.insert_vertex("North Nazimabad k mailay");

    g.insert_edge("Machar Colony", "Bhens Colony", 18);
    g.insert_edge("Machar Colony", "Mazar e Quaid", 18);

    g.insert_edge("Bhens Colony", "Soldier Bazar", 15);
    g.insert_edge("Bhens Colony", "Burns Road", 85);

    g.insert_edge("Mazar e Quaid", "Kati Pahaari", 20);
    g.insert_edge("Mazar e Quaid", "Layaari", 22);
    g.insert_edge("Kati Pahaari", "Soldier Bazar", 22);

    g.insert_edge("Kati Pahaari", "Teen Talwaar", 23);
    g.insert_edge("Kati Pahaari", "Layaari", 21);

    g.insert_edge("Teen Talwaar", "North Nazimabad k mailay", 19);

    g.insert_edge("Layaari", "Burns Road", 16);

    g.insert_edge("Burns Road", "North Nazimabad k mailay", 11);
    return g;
}

graph Multangraph()
{
    graph g;
    g.insert_vertex("DHA");
    g.insert_vertex("BZU");
    g.insert_vertex("Gulgasht Colony");
    g.insert_vertex("Royal Orchard");
    g.insert_vertex("Wapda Town");
    g.insert_vertex("Bypass");
    g.insert_vertex("Qasim Fort");
    g.insert_vertex("Multan Cantt");
    g.insert_vertex("Askari Colony");
    

    g.insert_edge("DHA", "BZU", 10);
    g.insert_edge("DHA", "Wapda Town", 15);

    g.insert_edge("DHA", "Royal Orchard", 18);
    g.insert_edge("BZU", "Bypass", 8);

    g.insert_edge("Royal Orchard", "Multan Cantt", 25);
    g.insert_edge("Wapda Town", "Gulgasht Colony", 14);
    g.insert_edge("Wapda Town", "Qasim Fort", 21);

    g.insert_edge("Bypass", "Qasim Fort", 22);
    g.insert_edge("Gulgasht Colony", "Multan Cantt",16);

    g.insert_edge("Gulgasht Colony", "Askari Colony", 17);

    g.insert_edge("Qasim Fort", "Askari Colony", 19);

    g.insert_edge("Multan Cantt", "Askari Colony", 3);

    return g;
}
graph PakistanGraph()
{
    graph g;
    g.insert_vertex("Gilgit");
    g.insert_vertex("Faisalabad");
    g.insert_vertex("Multan");
    g.insert_vertex("Islamabad");
    g.insert_vertex("Rawalpindi");
    g.insert_vertex("Lahore");
    g.insert_vertex("Quetta");
    g.insert_vertex("Gwadar");
    g.insert_vertex("Karachi");
    g.insert_vertex("Peshawar");


    g.insert_edge("Gilgit", "Islamabad", 300);
    g.insert_edge("Gilgit", "Faisalabad", 514);
    g.insert_edge("Gilgit", "Multan", 690);

    g.insert_edge("Islamabad", "Rawalpindi", 20);
    g.insert_edge("Islamabad", "Lahore", 377);

    g.insert_edge("Faisalabad", "Lahore", 184);
    g.insert_edge("Faisalabad", "Quetta", 596);

    g.insert_edge("Multan", "Quetta", 567);
    g.insert_edge("Multan", "Peshawar", 423);

    g.insert_edge("Rawalpindi", "Gwadar", 1800);
    g.insert_edge("Rawalpindi", "Karachi", 567);

    g.insert_edge("Lahore", "Karachi", 1035);
    g.insert_edge("Lahore", "Peshawar", 376);

    g.insert_edge("Quetta", "Peshawar", 604);

    g.insert_edge("Gwadar", "Karachi", 476);

    g.insert_edge("Peshawar", "Karachi", 1395);
    g.insert_edge("Multan", "Islamabad", 510);
    return g;
}
void Pak_search(graph Pakistan)
{
    string arr[] = { "Gilgit" ,"Quetta", "Islamabad", "Lahore" ,"Faisalabad" ,"Multan" ,"Gwadar" ,"Karachi" ,"Peshawar"};
    cout << "Choose Starting Point from the following" << endl;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        cout << i + 1 << ". " << arr[i] << endl;
    }
    int start_pnt; cin >> start_pnt;
    system("cls");
    cout << "Choose Ending Point from the following" << endl;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        cout << i + 1 << ". " << arr[i] << endl;
    }
    int end_pnt; cin >> end_pnt;
    system("cls");

    Pakistan.dijkstra(arr[start_pnt - 1], arr[end_pnt - 1]);

}
void Kir_search(graph Pakistan)
{
    string arr[] = { "Machar Colony" ,"Bhens Colony", "Soldier Bazar" ,"Kati Pahaari" ,"Teen Talwar" ,"Mazar e Quaid" ,"Burns Road" ,"Layaari","North Nazimabad"};
    cout << "Choose Starting Point from the following" << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << i + 1 << ". " << arr[i] << endl;
    }
    int start_pnt; cin >> start_pnt;
    system("cls");
    cout << "Choose Ending Point from the following" << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << i + 1 << ". " << arr[i] << endl;
    }
    int end_pnt; cin >> end_pnt;
    system("cls");

    Pakistan.dijkstra(arr[start_pnt - 1], arr[end_pnt - 1]);

}
void Mul_search(graph Pakistan)
{
    string arr[] = { "DHA" ,"BZU", "Wapda Town" ,"Bypass","Royal Orchard" ,"Gulgasht Colony" ,"Multan Cantt" ,"Qasim Fort" ,"Askari Colony"};
    cout << "Choose Starting Point from the following" << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << i + 1 << ". " << arr[i] << endl;
    }
    int start_pnt; cin >> start_pnt;
    system("cls");
    cout << "Choose Ending Point from the following" << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << i + 1 << ". " << arr[i] << endl;
    }
    int end_pnt; cin >> end_pnt;
    system("cls");

    Pakistan.dijkstra(arr[start_pnt - 1], arr[end_pnt - 1]);

}

int main()
{
    graph Pakistan = PakistanGraph();
    graph kiranchi = karachigraph();
    graph Multan = Multangraph();


    bool islooping = true;
    while (islooping)
    {
        cout << "--------------------Welcome To Our DS project ------------------- " << endl;
        cout << "\n********Program to Find The Shortest Route Between Two Points********\n";
        cout << "\n\nChoose The Region " << endl;
        cout << "Press 1 for Pakistan <3 <3 \nPress 2 for kiranchi (ew) \nPress 3 for Multan <3" << endl;
        int x;
        cin >> x;
        system("cls");
        switch (x)
        {
        case 1:
        {
            Pak_search(Pakistan);
            break;
        }
        case 2:
        {
            Kir_search(kiranchi);
            break;
        }
        case 3:
        {
            Mul_search(Multan);
            break;
        }
        }
        _getch();
        system("cls");
    }

    //cout << "----------------Kiranchi-------------------" << endl;
    //kiranchi.dijkstra("Machar Colony", "North Nazimabad k mailay");
    //cout << "----------------MULTAN-------------------" << endl;
    //Multan.dijkstra("DHA", "Askari Colony");
    //cout << "----------------Pakistan-------------------" << endl;
    //Pakistan.dijkstra("Gilgit", "Karachi");

}
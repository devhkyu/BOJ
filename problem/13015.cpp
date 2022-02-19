#include <iostream>

using namespace std;

void draw_first_and_last(int n, int a){
    for(int i=1;i<=n*2+a;i++){
        if(i <= n || i > n+a)
            cout << '*';
        else
            cout << ' ';
    }
    cout << endl;
}

void draw_stars(int n){
    for(int i=0;i<n;i++)
        cout << '*';
}

void draw_space(int n){
    for(int i=0;i<n;i++)
        cout << ' ';
}

int main(){
    int n;
    cin >> n;

    int a = n * 2 - 3;

    draw_first_and_last(n, a);

    for(int i=1;i<n;i++){
        draw_space(i);
        draw_stars(1);
        draw_space(n-2);
        draw_stars(1);
        if(i != n-1){
            draw_space(a-(i*2));
            draw_stars(1);
        }
        draw_space(n-2);
        draw_stars(1);
        cout << endl;
    }

    for(int i=n-2;i>=1;i--){
        draw_space(i);
        draw_stars(1);
        draw_space(n-2);
        draw_stars(1);
        draw_space(a-(i*2));
        draw_stars(1);
        draw_space(n-2);
        draw_stars(1);
        cout << endl;
    }

    draw_first_and_last(n, a);

    return 0;
}
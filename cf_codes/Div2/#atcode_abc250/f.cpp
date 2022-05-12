#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;

struct Point{
    ll x, y;
    Point operator + (const Point& p) const{
	    return {x + p.x, y + p.y};
    }

    Point operator - (const Point& p) const{
	    return {x - p.x, y - p.y};
    }

    long long operator ^ (const Point& p) const{
	    return x * p.y - y * p.x;
    }
};

std::vector<Point> points;
int n;

int main(){
    scanf("%d", &n);
    points.resize(n);
    for(int i = 0; i < n; i++){
	    scanf(" %lld %lld", &points[i].x, &points[i].y);
    }
    ll piza_area = 0;
    for(int i = 2; i < n; i++)
	    piza_area += std::abs((points[i-1]-points[0]) ^ (points[i]-points[0]));
    
    ll ans = INT64_MAX , get_area = 0ll;
    int qr = 1;
    for(int p = 0; p < n; p++){
	    while(4*get_area < piza_area){
            get_area += std::abs((points[qr]-points[p]) ^ (points[(qr+1)%n]-points[qr]));
	        qr = (qr+1)%n;
	        ans = std::min(ans, std::abs(4ll*get_area - piza_area));
	    }
	        get_area -= std::abs((points[p]-points[qr]) ^ (points[(p+1)%n]-points[qr]));
	        ans = std::min(ans, std::abs(4ll*get_area - piza_area));
    }
    printf("%lld\n", ans);
    return 0;
}












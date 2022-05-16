  - cpp
```cpp
#include <iostream>
using namespace std;

int main()
{
    double a = 0.0f, b = 0.0f;
    cin >> a >> b;
    cout.precision(9);
    cout << fixed;
    cout << (a / b) << endl;
    return 0;
}
```

  - java
```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = 0.0f, b = 0.0f;
        a = sc.nextDouble();
        b = sc.nextDouble();
        String result = String.format("%.9f", (a/b));
        System.out.println(result);
    }
}
```

#include <iostream>
#include <string>
#include <chrono> // Zamanlama için
#include <thread> // sleep_for için
#include <vector>

using namespace std;

struct Bilgiler {
    string Prompt;
    string IstenenSey; 
    float IslemIcinVerilenMaksSure; // Dakika cinsinden
};

// Yılan/Nokta efektini yapan fonksiyon
void renderEfekti(int toplamSaniye) {
    int maxNokta = 10;   // Yılanın gidebileceği maksimum uzaklık
    int suankiNokta = 0;
    int yon = 1;         // 1 sağa, -1 sola

    auto baslangic = chrono::steady_clock::now();
    
    while (true) {
        auto simdi = chrono::steady_clock::now();
        auto gecenSure = chrono::duration_cast<chrono::seconds>(simdi - baslangic).count();
        
        if (gecenSure >= toplamSaniye) break; // Süre dolunca çık

      
        system("clear"); 

        cout << "--- AYG LABS RENDER ENGINE ---" << endl;
        cout << "Durum: Isleniyor..." << endl;
        
        // Noktaları çizdirme mantığı
        for (int i = 0; i < suankiNokta; ++i) cout << " "; // Boşluk bırak
        cout << "...";
        cout << endl;

        // Yön değiştirme mantığı (Yılanın geri dönmesi)
        suankiNokta += yon;
        if (suankiNokta >= maxNokta || suankiNokta <= 0) {
            yon *= -1; // Sona gelince ters yöne dön
        }

        this_thread::sleep_for(chrono::milliseconds(100)); // Hız ayarı
    }
    cout << "\nRender Tamamlandi!" << endl;
}

int main() {
    Bilgiler yeniGorev;

    cout << "AYG-CGI Deneme Sistemine Hos Geldiniz!\n" << endl;
    
    cout << "Prompt giriniz: ";
    getline(cin, yeniGorev.Prompt);
    
    cout << "Istenen Sey (Video/Fotograf): ";
    cin >> yeniGorev.IstenenSey;
    
    cout << "Maksimum Sure (Dakika): ";
    cin >> yeniGorev.IslemIcinVerilenMaksSure;
  
    int toplamSaniye = yeniGorev.IslemIcinVerilenMaksSure * 60;

    cout << "\nSistem baslatiliyor..." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    // Animasyonu başlat
    renderEfekti(toplamSaniye);

    return 0;
}

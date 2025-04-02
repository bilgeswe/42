#include <unistd.h>
#include <fcntl.h>

void ft_putnbr(int nb, int fd) {
    // Eğer sayı en küçük tam sayıysa, bu durumu ele al
    if (nb == -2147483648) {
        write(fd, "-2147483648", 11);
        return;
    }

    // Negatif sayılar için işareti yaz ve pozitif hale getir
    if (nb < 0) {
        write(fd, "-", 1);
        nb = -nb;
    }

    // Sayının ondalık kısmına bölerek devam et
    if (nb >= 10) {
        ft_putnbr(nb / 10, fd);
        nb = nb % 10;
    }

    // Son basamağı yaz (0-9 arası bir rakam)
    if (nb < 10) {
        char c = nb + '0';  // `nb`'yi karaktere dönüştür
        write(fd, &c, 1);   // Karakterin adresini yaz
    }
}

int main(void) {
    int fd = open("a.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);


    ft_putnbr(1234567, fd);

    // Dosyayı kapat
    close(fd);

    return 0;
}
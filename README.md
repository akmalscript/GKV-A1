# 📚 GKV Assignment  

## 📌 Tugas Praktikum 2  
✅ [Click here](https://github.com/akmalscript/GKV-A1/tree/main/Tugas%20Praktikum%202) to access the files  
🚗 Cybertruck, but it's low budget 😂😂

![Cybertruck Render](/Tugas%20Praktikum%202/mobil.png)  

## 📌 Tugas Praktikum 3  
**Free** penugasan **Tugas Praktikum 3** karena sudah membuat lengan tambahan serta maju untuk menjelaskan saat praktikum di lab.

## 📌 Tugas Praktikum 4  
✅ [Click here](https://github.com/akmalscript/GKV-A1/tree/main/Tugas%20Praktikum%204) to access the files

![Kubus3D Render](/Tugas%20Praktikum%204/gambar%20kubus.png)  
### Warna Background
```c
// Mengatur warna latar belakang langit menjadi biru gelap malam
glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
```

### Warna Kubus
```c
// Mengatur warna kubus menjadi biru tua/navy
glColor3f(0.1f, 0.1f, 0.5f);
```

### Mengurangi Sensitivitas Gerakan Maju/Mundur
```c
// Sebelumnya
x = x + i*(lx)*0.1;
z = z + i*(lz)*0.1;

// Setelah dikurangi
x = x + i*(lx)*0.03;
z = z + i*(lz)*0.03;
```

### Mengurangi Sensitivitas Belok Kanan/Kiri
```c
// Sebelumnya
case GLUT_KEY_LEFT : deltaAngle = -0.01f;break;
case GLUT_KEY_RIGHT : deltaAngle = 0.01f;break;

// Setelah dikurangi
case GLUT_KEY_LEFT : deltaAngle = -0.003f;break;
case GLUT_KEY_RIGHT : deltaAngle = 0.003f;break;
```

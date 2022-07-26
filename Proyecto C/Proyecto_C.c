#include <stdlib.h>
#include <gtk/gtk.h>


static int control_boton00 = 0;
static int control_boton01 = 0;
static int control_boton02 = 0;
static int control_boton10 = 0;
static int control_boton11 = 0;
static int control_boton12 = 0;
static int control_boton20 = 0;
static int control_boton21 = 0;
static int control_boton22 = 0;
// Como regla tipica del juego gato, la X siempre inicia,
// impar = 'X' y par = 'O'.
static int control_jugador = 0;
static int control_ganador = 0;
static int ganadorO = 0;
static int ganadorX = 0;
static int tablero[3][3]= {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};

void alguien_gano(){
  if (tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2] && tablero[0][0] != 0 ||
    tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2] && tablero[1][0] != 0 ||
    tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2] && tablero[2][0] != 0 ||
    tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0] && tablero[0][0] != 0 ||
    tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1] && tablero[0][1] != 0 ||
    tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2] && tablero[0][2] != 0 ||
    tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2] && tablero[0][0] != 0 ||
    tablero[2][0] == tablero[1][1] && tablero[2][0] == tablero[0][2] && tablero[2][0] != 0 ){
        // En caso de ser ganador, se modifica el atributo de control para el ganador.
        control_ganador = 1;
  }

  if (control_ganador == 1){
      printf("juego terminado \n");
      if (control_jugador%2==0) { // Es par es circulo
        printf("\nGanaron los circulos\n");
        control_boton00 = 1;
        control_boton01 = 1;
        control_boton02 = 1;
        control_boton10 = 1;
        control_boton11 = 1;
        control_boton12 = 1;
        control_boton20 = 1;
        control_boton21 = 1;
        control_boton22 = 1;
        ganadorO = 1;
      }
      else{
        printf("\nGanaron las equis\n");
        control_boton00 = 1;
        control_boton01 = 1;
        control_boton02 = 1;
        control_boton10 = 1;
        control_boton11 = 1;
        control_boton12 = 1;
        control_boton20 = 1;
        control_boton21 = 1;
        control_boton22 = 1;
        ganadorX = 1;
      }
  }
}


int main(int argc, char* argv[]) {
    GtkBuilder *builder;
    GtkWidget *window;
    GtkWidget *boton_00;
    GtkWidget *boton_01;
    GtkWidget *boton_02;
    GtkWidget *boton_10;
    GtkWidget *boton_11;
    GtkWidget *boton_12;
    GtkWidget *boton_20;
    GtkWidget *boton_21;
    GtkWidget *boton_22;
    GtkWidget *boton_reinicio;
    GtkWidget *boton_salir;
    GtkWidget *label_estado_turno;

    // int control_boton00 = 0;
    // int control_boton01 = 0;
    // int control_boton02 = 0;
    // int control_boton10 = 0;
    // int control_boton11 = 0;
    // int control_boton12 = 0;
    // int control_boton20 = 0;
    // int control_boton21 = 0;
    // int control_boton22 = 0;
    // // Como regla tipica del juego gato, la X siempre inicia,
    // // impar = 'X' y par = 'O'.
    // int control_jugador = 0;
    // int tablero[3][3]= {
    //   {0, 0, 0},
    //   {0, 0, 0},
    //   {0, 0, 0}
    // };

    gtk_init(&argc, &argv);

    // Get GUI from file
    builder = gtk_builder_new_from_file(
        "Interfaz_gato.glade");

    window = GTK_WIDGET(
      gtk_builder_get_object(builder, "Ventana_Principal")
    );
    g_signal_connect(
      window, "destroy", G_CALLBACK(gtk_main_quit), NULL
    );

    boton_00 = GTK_WIDGET(
      gtk_builder_get_object(builder, "boton_00")
    );
    boton_01 = GTK_WIDGET(
      gtk_builder_get_object(builder, "boton_01")
    );
    boton_02 = GTK_WIDGET(
      gtk_builder_get_object(builder, "boton_02")
    );
    boton_10 = GTK_WIDGET(
      gtk_builder_get_object(builder, "boton_10")
    );
    boton_11 = GTK_WIDGET(
      gtk_builder_get_object(builder, "boton_11")
    );
    boton_12 = GTK_WIDGET(
      gtk_builder_get_object(builder, "boton_12")
    );
    boton_20 = GTK_WIDGET(
      gtk_builder_get_object(builder, "boton_20")
    );
    boton_21 = GTK_WIDGET(
      gtk_builder_get_object(builder, "boton_21")
    );
    boton_22 = GTK_WIDGET(
      gtk_builder_get_object(builder, "boton_22")
    );
    label_estado_turno = GTK_WIDGET(
      gtk_builder_get_object(builder, "label_estado_turno")
    );
    boton_reinicio = GTK_WIDGET(
      gtk_builder_get_object(builder, "boton_reinicio")
    );
    boton_salir = GTK_WIDGET(
      gtk_builder_get_object(builder, "boton_salir")
    );

    void boton00Apetado(GtkWidget *widget, gpointer data) {
      GtkLabel *label = (GtkLabel*) data;
      GtkButton *botonTemp = (GtkButton *) data;
      GtkWidget *imageO1 = gtk_image_new_from_file ("o.jpg");
      GtkWidget *imageX1 = gtk_image_new_from_file ("x.jpg");

      // Entra si el boton no ha sido apretado.
      if (control_boton00 == 0) {
        control_boton00++;

        // Se identifica si juega el circulo, num % 2 == 0 es par.
        if (++control_jugador % 2 == 0) { // Es par, juega circulo.
          // Se identifica la casilla para el circulo como 1.
          tablero[0][0] = 1;
          gtk_button_set_image (GTK_BUTTON (boton_00), imageO1);
          gtk_label_set_text(label, "Ahora juega la X");
        }
        else{// Es impar, juega equis.
          // Se identifica la casilla para el circulo como 1.
          tablero[0][0] = 2;
          gtk_button_set_image (GTK_BUTTON (boton_00), imageX1);
          gtk_label_set_text(label, "Ahora juega la O");
        }
      }
      // Se revisa si alguien ha ganado
      alguien_gano();

    }

    void boton01Apetado(GtkWidget *widget, gpointer data) {
      GtkLabel *label = (GtkLabel*) data;
      GtkButton *botonTemp = (GtkButton *) data;
      GtkWidget *imageO = gtk_image_new_from_file ("o.jpg");
      GtkWidget *imageX = gtk_image_new_from_file ("x.jpg");

      // Entra si el boton no ha sido apretado.
      if (control_boton01 == 0) { // Es par, juega circulo.
        control_boton01++;

        // Se identifica si juega el circulo, num % 2 == 0 es par.
        if (++control_jugador % 2 == 0) { // Es par, juega circulo.
          // Se identifica la casilla para el circulo como 1.
          tablero[0][1] = 1;
          gtk_button_set_image (GTK_BUTTON (boton_01), imageO);
          gtk_label_set_text(label, "Ahora juega la X");
        }
        else{// Es impar, juega equis.
          // Se identifica la casilla para el circulo como 1.
          tablero[0][1] = 2;
          gtk_button_set_image (GTK_BUTTON (boton_01), imageX);
          gtk_label_set_text(label, "Ahora juega la O");
        }
      }
      // Se revisa si alguien ha ganado
      alguien_gano();

    }


    void boton02Apetado(GtkWidget *widget, gpointer data) {
      GtkLabel *label = (GtkLabel*) data;
      GtkButton *botonTemp = (GtkButton *) data;
      GtkWidget *imageO = gtk_image_new_from_file ("o.jpg");
      GtkWidget *imageX = gtk_image_new_from_file ("x.jpg");

      // Entra si el boton no ha sido apretado.
      if (control_boton02 == 0) { // Es par, juega circulo.
        control_boton02++;

        // Se identifica si juega el circulo, num % 2 == 0 es par.
        if (++control_jugador % 2 == 0) { // Es par, juega circulo.
          // Se identifica la casilla para el circulo como 1.
          tablero[0][2] = 1;
          gtk_button_set_image (GTK_BUTTON (boton_02), imageO);
          gtk_label_set_text(label, "Ahora juega la X");
        }
        else{// Es impar, juega equis.
          // Se identifica la casilla para el circulo como 1.
          tablero[0][2] = 2;
          gtk_button_set_image (GTK_BUTTON (boton_02), imageX);
          gtk_label_set_text(label, "Ahora juega la O");
        }
      }
      // Se revisa si alguien ha ganado
      alguien_gano();

    }

    void boton10Apetado(GtkWidget *widget, gpointer data) {
      GtkLabel *label = (GtkLabel*) data;
      GtkButton *botonTemp = (GtkButton *) data;
      GtkWidget *imageO = gtk_image_new_from_file ("o.jpg");
      GtkWidget *imageX = gtk_image_new_from_file ("x.jpg");

      // Entra si el boton no ha sido apretado.
      if (control_boton10 == 0) { // Es par, juega circulo.
        control_boton10++;

        // Se identifica si juega el circulo, num % 2 == 0 es par.
        if (++control_jugador % 2 == 0) { // Es par, juega circulo.
          // Se identifica la casilla para el circulo como 1.
          tablero[1][0] = 1;
          gtk_button_set_image (GTK_BUTTON (boton_10), imageO);
          gtk_label_set_text(label, "Ahora juega la X");
        }
        else{// Es impar, juega equis.
          // Se identifica la casilla para el circulo como 1.
          tablero[1][0] = 2;
          gtk_button_set_image (GTK_BUTTON (boton_10), imageX);
          gtk_label_set_text(label, "Ahora juega la O");
        }
      }
      // Se revisa si alguien ha ganado
      alguien_gano();

    }

    void boton11Apetado(GtkWidget *widget, gpointer data) {
      GtkLabel *label = (GtkLabel*) data;
      GtkButton *botonTemp = (GtkButton *) data;
      GtkWidget *imageO = gtk_image_new_from_file ("o.jpg");
      GtkWidget *imageX = gtk_image_new_from_file ("x.jpg");

      // Entra si el boton no ha sido apretado.
      if (control_boton11 == 0) { // Es par, juega circulo.
        control_boton11++;

        // Se identifica si juega el circulo, num % 2 == 0 es par.
        if (++control_jugador % 2 == 0) { // Es par, juega circulo.
          // Se identifica la casilla para el circulo como 1.
          tablero[1][1] = 1;
          gtk_button_set_image (GTK_BUTTON (boton_11), imageO);
          gtk_label_set_text(label, "Ahora juega la X");
        }
        else{// Es impar, juega equis.
          // Se identifica la casilla para el circulo como 1.
          tablero[1][1] = 2;
          gtk_button_set_image (GTK_BUTTON (boton_11), imageX);
          gtk_label_set_text(label, "Ahora juega la O");
        }
      }
      // Se revisa si alguien ha ganado
      alguien_gano();

    }

    void boton12Apetado(GtkWidget *widget, gpointer data) {
      GtkLabel *label = (GtkLabel*) data;
      GtkButton *botonTemp = (GtkButton *) data;
      GtkWidget *imageO = gtk_image_new_from_file ("o.jpg");
      GtkWidget *imageX = gtk_image_new_from_file ("x.jpg");

      // Entra si el boton no ha sido apretado.
      if (control_boton12 == 0) { // Es par, juega circulo.
        control_boton12++;

        // Se identifica si juega el circulo, num % 2 == 0 es par.
        if (++control_jugador % 2 == 0) { // Es par, juega circulo.
          // Se identifica la casilla para el circulo como 1.
          tablero[1][2] = 1;
          gtk_button_set_image (GTK_BUTTON (boton_12), imageO);
          gtk_label_set_text(label, "Ahora juega la X");
        }
        else{// Es impar, juega equis.
          // Se identifica la casilla para el circulo como 1.
          tablero[1][2] = 2;
          gtk_button_set_image (GTK_BUTTON (boton_12), imageX);
          gtk_label_set_text(label, "Ahora juega la O");
        }
      }
      // Se revisa si alguien ha ganado
      alguien_gano();

    }

    void boton20Apetado(GtkWidget *widget, gpointer data) {
      GtkLabel *label = (GtkLabel*) data;
      GtkButton *botonTemp = (GtkButton *) data;
      GtkWidget *imageO = gtk_image_new_from_file ("o.jpg");
      GtkWidget *imageX = gtk_image_new_from_file ("x.jpg");

      // Entra si el boton no ha sido apretado.
      if (control_boton20 == 0) { // Es par, juega circulo.
        control_boton20++;

        // Se identifica si juega el circulo, num % 2 == 0 es par.
        if (++control_jugador % 2 == 0) { // Es par, juega circulo.
          // Se identifica la casilla para el circulo como 1.
          tablero[2][0] = 1;
          gtk_button_set_image (GTK_BUTTON (boton_20), imageO);
          gtk_label_set_text(label, "Ahora juega la X");
        }
        else{// Es impar, juega equis.
          // Se identifica la casilla para el circulo como 1.
          tablero[2][0] = 2;
          gtk_button_set_image (GTK_BUTTON (boton_20), imageX);
          gtk_label_set_text(label, "Ahora juega la O");
        }
      }
      // Se revisa si alguien ha ganado
      alguien_gano();

    }

    void boton21Apetado(GtkWidget *widget, gpointer data) {
      GtkLabel *label = (GtkLabel*) data;
      GtkButton *botonTemp = (GtkButton *) data;
      GtkWidget *imageO = gtk_image_new_from_file ("o.jpg");
      GtkWidget *imageX = gtk_image_new_from_file ("x.jpg");

      // Entra si el boton no ha sido apretado.
      if (control_boton21 == 0) { // Es par, juega circulo.
        control_boton21++;

        // Se identifica si juega el circulo, num % 2 == 0 es par.
        if (++control_jugador % 2 == 0) { // Es par, juega circulo.
          // Se identifica la casilla para el circulo como 1.
          tablero[2][1] = 1;
          gtk_button_set_image (GTK_BUTTON (boton_21), imageO);
          gtk_label_set_text(label, "Ahora juega la X");
        }
        else{// Es impar, juega equis.
          // Se identifica la casilla para el circulo como 1.
          tablero[2][1] = 2;
          gtk_button_set_image (GTK_BUTTON (boton_21), imageX);
          gtk_label_set_text(label, "Ahora juega la O");
        }
      }
      // Se revisa si alguien ha ganado
      alguien_gano();

    }

    void boton22Apetado(GtkWidget *widget, gpointer data) {
      GtkLabel *label = (GtkLabel*) data;
      GtkButton *botonTemp = (GtkButton *) data;
      GtkWidget *imageO = gtk_image_new_from_file ("o.jpg");
      GtkWidget *imageX = gtk_image_new_from_file ("x.jpg");

      // Entra si el boton no ha sido apretado.
      if (control_boton22 == 0) { // Es par, juega circulo.
        control_boton22++;

        // Se identifica si juega el circulo, num % 2 == 0 es par.
        if (++control_jugador % 2 == 0) { // Es par, juega circulo.
          // Se identifica la casilla para el circulo como 1.
          tablero[2][2] = 1;
          gtk_button_set_image (GTK_BUTTON (boton_22), imageO);
          gtk_label_set_text(label, "Ahora juega la X");
        }
        else{// Es impar, juega equis.
          // Se identifica la casilla para el circulo como 1.
          tablero[2][2] = 2;
          gtk_button_set_image (GTK_BUTTON (boton_22), imageX);
          gtk_label_set_text(label, "Ahora juega la O");
        }
      }
      // Se revisa si alguien ha ganado
      alguien_gano();

    }


    // Se define el void para cuando se estripa el boton de reiniciar
    void reiniciarApetado(GtkWidget *widget, gpointer data){
      GtkLabel *label = (GtkLabel*) data;
      GtkButton *botonTemp = (GtkButton *) data;
      // Se devuelven las variables de control a su valor de inicio
      control_boton00 = 0;
      control_boton01 = 0;
      control_boton02 = 0;
      control_boton10 = 0;
      control_boton11 = 0;
      control_boton12 = 0;
      control_boton20 = 0;
      control_boton21 = 0;
      control_boton22 = 0;
      control_jugador = 0;
      control_ganador = 0;
      // Se reinicia el tablero
      for(int i=0;i<3;i++)
      {
        for(int j=0;j<3;j++)
        {
          tablero[i][j] = 0;
        }
      }
      GtkWidget *imageVacio1 = gtk_image_new_from_file ("Vacio.jpg");
      GtkWidget *imageVacio2 = gtk_image_new_from_file ("Vacio.jpg");
      GtkWidget *imageVacio3 = gtk_image_new_from_file ("Vacio.jpg");
      GtkWidget *imageVacio4 = gtk_image_new_from_file ("Vacio.jpg");
      GtkWidget *imageVacio5 = gtk_image_new_from_file ("Vacio.jpg");
      GtkWidget *imageVacio6 = gtk_image_new_from_file ("Vacio.jpg");
      GtkWidget *imageVacio7 = gtk_image_new_from_file ("Vacio.jpg");
      GtkWidget *imageVacio8 = gtk_image_new_from_file ("Vacio.jpg");
      GtkWidget *imageVacio9 = gtk_image_new_from_file ("Vacio.jpg");
      gtk_button_set_image (GTK_BUTTON (boton_00), imageVacio1);
      gtk_button_set_image (GTK_BUTTON (boton_01), imageVacio2);
      gtk_button_set_image (GTK_BUTTON (boton_02), imageVacio3);
      gtk_button_set_image (GTK_BUTTON (boton_10), imageVacio4);
      gtk_button_set_image (GTK_BUTTON (boton_11), imageVacio5);
      gtk_button_set_image (GTK_BUTTON (boton_12), imageVacio6);
      gtk_button_set_image (GTK_BUTTON (boton_20), imageVacio7);
      gtk_button_set_image (GTK_BUTTON (boton_21), imageVacio8);
      gtk_button_set_image (GTK_BUTTON (boton_22), imageVacio9);
    }

    // Se define el void para cuando se estripa el boton de salir
    void salirApetado(GtkWidget *widget, gpointer data){
      gtk_main_quit();
      exit(0);
    }

    g_signal_connect(
      boton_00, "clicked", G_CALLBACK(boton00Apetado), label_estado_turno
    );
    g_signal_connect(
      boton_01, "clicked", G_CALLBACK(boton01Apetado), label_estado_turno
    );
    g_signal_connect(
      boton_02, "clicked", G_CALLBACK(boton02Apetado), label_estado_turno
    );
    g_signal_connect(
      boton_10, "clicked", G_CALLBACK(boton10Apetado), label_estado_turno
    );
    g_signal_connect(
      boton_11, "clicked", G_CALLBACK(boton11Apetado), label_estado_turno
    );
    g_signal_connect(
      boton_12, "clicked", G_CALLBACK(boton12Apetado), label_estado_turno
    );
    g_signal_connect(
      boton_20, "clicked", G_CALLBACK(boton20Apetado), label_estado_turno
    );
    g_signal_connect(
      boton_21, "clicked", G_CALLBACK(boton21Apetado), label_estado_turno
    );
    g_signal_connect(
      boton_22, "clicked", G_CALLBACK(boton22Apetado), label_estado_turno
    );
    g_signal_connect(
      boton_reinicio, "clicked", G_CALLBACK(reiniciarApetado), label_estado_turno
    );
    g_signal_connect(
      boton_salir, "clicked", G_CALLBACK(salirApetado), label_estado_turno
    );

    gtk_builder_connect_signals(builder, NULL);


    // Show and start main loop
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

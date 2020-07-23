#include <gtk/gtk.h>

/* 
 * Constructs the GTK window, so it is shown when the application is launched.
 */
static void activate (GtkApplication* app, gpointer user_data)
{
	GtkWidget *window;

	/* Creates a new GtkWindow and store it inside the window pointer*/
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Window KUNI");
	gtk_window_set_default_size (GTK_WINDOW(window), 400, 400);
	gtk_widget_show_all(window);
}

/*
 * Creates a GtkApplication object and run it. 
 * A GtkApplication pointer named "app" is called and 
 * then initialize using "gtk_aplication_new()"
 */
int main (int argc, char **argv)
{
	GtkApplication *app;
	int status;

	/* "org.gtk.example": is the application identifier
	 * G_APPLICATION_FLAGS_NONE : GApplicationFlags for the app */
	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);

	/* The activate signal is connected to the activate() function, signal sent when
	 * the application is launched with "g_application_run()" */
	g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);

	/* Takes as arguments the pointers to the command line arguments countr
	 * and string array; in order to parse specific command line argument that
	 * control the behavior of GTK++ */
	status = g_application_run (G_APPLICATION (app), argc, argv);

	/* The GtkApplication object is freed from memory */
	g_object_unref (app);

	return status;
}

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

// Function to handle the "Quit" button click
static void on_quit_button_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

// Function to handle text entry
static void on_text_entry_changed(GtkWidget *widget, gpointer data) {
    const char *text = gtk_entry_get_text(GTK_ENTRY(widget));
    printf("Text entered: %s\n", text);
}

// Function to create the main application window
void create_window() {
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *button_quit;
    GtkWidget *entry;
    GtkWidget *notebook;
    GtkWidget *tab1;
    GtkWidget *tab2;
    GtkWidget *label;
    
    gtk_init(NULL, NULL);

    // Create a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Simple Application");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a vertical box to hold widgets
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Create a "Quit" button
    button_quit = gtk_button_new_with_label("Quit");
    g_signal_connect(button_quit, "clicked", G_CALLBACK(on_quit_button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), button_quit, FALSE, FALSE, 0);

    // Create a text entry field and connect the signal for change
    entry = gtk_entry_new();
    g_signal_connect(entry, "changed", G_CALLBACK(on_text_entry_changed), NULL);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);

    // Create a notebook (tab interface)
    notebook = gtk_notebook_new();
    gtk_box_pack_start(GTK_BOX(box), notebook, TRUE, TRUE, 0);

    // Create two tabs
    tab1 = gtk_label_new("Tab 1");
    tab2 = gtk_label_new("Tab 2");

    // First tab content
    label = gtk_label_new("This is the first tab.");
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), label, tab1);

    // Second tab content
    label = gtk_label_new("This is the second tab.");
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), label, tab2);

    // Show all widgets
    gtk_widget_show_all(window);

    // Main event loop
    gtk_main();
}

int main(int argc, char *argv[]) {
    create_window();
    return 0;
}

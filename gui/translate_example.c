
/*
 * To Compile
 * 
 * gcc -o translate_example translate_example.c -Wall -g `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
 * 
 */

#include <gtk-3.0/gtk/gtk.h>
#include <cairo.h>
#include <stdlib.h>
#include <time.h>



/* ToDo: The bit that is outstanding is getting 0,0 fo rthe data at bottom left, not top left */


void on_draw (GtkWidget *drawing, cairo_t *cr) {
        //Info: cr is passed as an extra parameter which is set in the glade file as user data.
    
    GdkRectangle da;            /* GtkDrawingArea size */
    gdouble dx = 1.0, dy = 1.0; /* Pixels between each point at USER level (See Scale below)*/
    gdouble clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = 0.0, clip_y2 = 0.0;
    gdouble left_margin = 5.0, bottom_margin = 5.0;         /* gap between edge and lines, percentage */
    gdouble x_scale = 1.0, y_scale = 1.0;


    // Temporary code to create a dataset..
    float     dataset[101];
    float     max = 0, min = 0;
    int     j, qty = 0;
    
    //for(j=0; j < 100; j++) {
    for(j=0; j < (rand() % 100); j++) {
        dataset[j] = (float)(rand() % 1000); // / 105;
        //dataset[j] = j;
        if (dataset[j] > max) {
            max = dataset[j];
        }
        else if (dataset[j] < min) {
            min = dataset[j];
        }
    }
    qty = j;
    printf("min :%lf ", min);
    printf("max :%lf ", max);
    printf("count :%d\n", qty);



    GdkWindow *window = gtk_widget_get_window(drawing);     // I Think this needs to be the drawing canvas

    /* Determine GtkDrawingArea dimensions */
    gdk_window_get_geometry (window,
            &da.x,
            &da.y,
            &da.width,
            &da.height);

    printf("Got window geometry\n");
    printf("X coord:%d ", da.x);
    printf("Y coord:%d ", da.y);
    printf("Width  :%d ", da.width);
    printf("Height :%d\n", da.height);

    /* Draw on a black background */
    cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
    cairo_paint (cr);
    printf("Drawn black background\n");

    /* Change the transformation matrix */
    // 1 cairo_translate (cr, -da.width, -da.height);
    // 2 cairo_translate (cr, da.width, da.height);
    // 3 cairo_translate (cr, 0, 0);
    cairo_translate (cr, 0, 0);         // No movememt of the x and y zero positions
                                        // Translate is used to set where 0,0 is, default is top left
    
    cairo_scale (cr, (da.width / 100), (da.height / 100));      // Sets the box to be 100 x 100, regardless of window
    //cairo_scale (cr, 1, 1);           // Setting the scale of the user transformation, e.g. 1x1 or 100x100
                                        // A scale of 100x100 means that 100 pixels at the device level is 1 at user level so
                                        // coordinates need to be in the required range.
                                        // e.g. a size of 300 x 300 pixels at device level is converted to 3 x 3 at user level, so coord need to be
                                        //  in this smaller range. clip_x1/2 and clip_y1/2 show the range being used and can be used to set scale.
    
    printf("changed the transformation matrix\n");

    /* Determine the data points to calculate (ie. those in the clipping zone */
    cairo_device_to_user_distance (cr, &dx, &dy);       // Converting a scale of 1 by 1 (default) to whatever is required for 
                                                        // the actual conversion of device space to user space
                                                        // This can then be used to set certain sizes.
                                                        // Afrer this dx and dy are in the device space scale, which is very useful for line widths etc.
    cairo_clip_extents (cr, &clip_x1, &clip_y1, &clip_x2, &clip_y2);
    
    x_scale = ((clip_x2 - clip_x1 - left_margin) / qty);
    y_scale = ((clip_y2 - bottom_margin - clip_y1) / (max - min));
    
    cairo_set_line_width (cr, dx);
    printf("Determined the data points\n");
    printf("dx:%lf dy:%lf\n", dx, dy);
    printf("clip_x1:%lf ", clip_x1);
    printf("clip_x2:%lf ", clip_x2);
    printf("clip_y1:%lf ", clip_y1);
    printf("clip_y2:%lf\n", clip_y2);
    printf("X scale:%lf ", x_scale);
    printf("Y scale:%lf\n", y_scale);
    

    /* Draws x and y axis */
    cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
    // horizontal axis
    cairo_move_to (cr, clip_x1+left_margin, clip_y2-bottom_margin);
    cairo_line_to (cr, clip_x2, clip_y2-bottom_margin);
    // vertical axis
    cairo_move_to (cr, clip_x1+left_margin, clip_y1);
    cairo_line_to (cr, clip_x1+left_margin, clip_y2-bottom_margin);
    cairo_stroke (cr);
    printf("drawn x and y axis\n");

    /* Draw the graph */

    /* Link each data point */

    // for (i = clip_x1; i < clip_x2; i += dx) {
    cairo_set_source_rgba (cr, 1, 0.2, 0.2, 0.6);
    cairo_move_to (cr, (clip_x1+left_margin), (clip_y2 - bottom_margin) - (dataset[0] * y_scale));
    for (j = 0; j < qty; j ++) {
        printf("%d¡:%f\n", j, dataset[j]);
        cairo_line_to (cr, (j * x_scale)+left_margin, (clip_y2 - bottom_margin) - (dataset[j] * y_scale));      //Draws a line from the current position, to the new coordinates

    }
    cairo_stroke (cr);

    /* Draw an additional line in a different colour to check graph */
    cairo_set_source_rgba (cr, 1, 0.5, 0.5, 0.6);
    cairo_move_to(cr, (j * x_scale) +left_margin , (clip_y2 - bottom_margin) - (j * y_scale) );
    cairo_line_to(cr, 10, 50);
    cairo_stroke (cr);
    printf("Drawn the graph\n");
    return;

}

int main (int argc, char *argv[])
{
        GtkWidget *window;
        
        srand(time(0));

        gtk_init (&argc, &argv);
        window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
        g_signal_connect (window, "draw", G_CALLBACK (on_draw), NULL);
        g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
        gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size (GTK_WINDOW(window), 300, 300);
        gtk_widget_set_app_paintable (window, TRUE);
        gtk_widget_show_all (window);
        gtk_main ();
        return 0;
}


/* EOF */

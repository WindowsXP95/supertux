#ifndef SUPERTUX_HEADER_MATH_POLYGON
#define SUPERTUX_HEADER_MATH_POLYGON
#include "math/vector.hpp"
#include <vector>
class Polygon {
  public:
    /**
     *  Adds a vertice to this polygon.
     *  @param point The new vertice
     */
    void add_vertice( Vector point );
    /**
     * Checks for overlapping vertices and marks normals using those as disabled.
     * @param b The neighbouring polygon.
     **/
    void process_neighbor(Polygon& b);
    /**
     *  Checks octile adjacent neighbours for normals which have to be deactivated.
     **/
    void process_octile_neighbour(int dir, Polygon& b);
    /**
     *  Handles a collision between the tile and a moving object.
     *  Returns the axis of resolution.
     *
     *  @param b The polygon to check collisions against
     */
     void handle_collision(Polygon& b);
     /**
      * Flags every normal colinear with n to be ignored.
      * @param n The normal to flag as ignored.
      */
     void disable_normal(const Vector& n);
     /**
      *  Checks if the axis represented by the vector
      *  is seperating (i.e the polygons do not overlap if projected onto the axis)
      *
      *  @param b The second polygon
      *  @param axis The vector representing the axis
      */
     bool Polygon::is_seperating_axis(Polygon& b, Vector& axis)
     /**
      * Inits the normal_enabled vector.
      * Call after polygon all edges were added.
      */
      void setup();
  private:
    std::vector< Vector > vertices;
    std::vector< Vector > edges;
    std::vector< Vector > normals; /** Edge normals */

    std::vector< bool > normal_enabled; /** Saves for every normal a flag indicating wether it is enabled. */
};
#endif

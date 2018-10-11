#include <iostream>
#include <list>

using namespace std;

#include "Point.h"

struct HalfEdge; // forward declare
                 // so Vertex and Face know what a HalfEdge is

struct Vertex {
    Point p
    HalfEdge* leaving;
    Vertex(Point a) : p(a), leaving(NULL) {};
};

struct Face {
    HalfEdge* edge;
    Face() : edge(NULL) {};
    Face(HalfEdge* e) : edge(e) {};
};

struct HalfEdge {
    Vertex* origin;
    Face* face;
    HalfEdge* twin;
    HalfEdge* next;
    HalfEdge(Vertex* v) : origin(v), face(NULL), twin(NULL), next(NULL) {};
    HalfEdge(Vertex* v, Face* f) : origin(v), face(f), twin(NULL), next(NULL) {};
};

struct DCEL {
    // data list
    list<Vertex*> vertices;
    list<Face*> faces;
    list<HalfEdge*> edges;

    list<Vertex*> boundaryVertices(Face*);
    list<Face*> adjacentFaces(Face* face);
    void connectVertices(Vertex* a, Vertex* b);
    void createVertex(Vertex* a, Vertex* b);
};

typedef Vertex* PVertex;
typedef Face* PFace;
typedef HalfEdge* PEdge;

list<Vertex*> DCEL::boundaryVertices(Face* face) {
    // create a list to store results
    list<Vertex*> result;

    // pointer for our current edge
    HalfEdge* current = face->edge;

    // loop through all the edges
    do {
        // add the current edge’s vertex
        result.push_back(current->origin);

        // go to the next edge
        current = current->next;
    } while (current != face->edge);

    // return the list
    return result;
}

list<Face*> DCEL::adjacentFaces(Face* face) {
    // create a list to store results
    list<Face*> adjacent;
    // create a hash to check who we visited
    unordered_map<Face*, bool> visited;
    
    // pointer for our current edge
    HalfEdge* current = face->edge;

    // loop through all the edges
    do {
        // get face on other side
        Face* adj = current->twin->face;

        // if we dont have the face add it
        if (visited.find(adj) == visited.end()) {
            adjacent.push_back(adj);
            visited[adj] = true;
        }
        // go to the next edge
        current = current->next;
    } while (current != face->edge);
};

void connectVertices(Vertex* a, Vertex* b) {
    Face* oldface = NULL;
    
    // find the face containing both a and b
    // if multiple faces have both, then an edge already exist
    for (int i = 0; i < faces.size(); i++) {
        list<Vertex*> in = boundaryVertices(faces.at(i));
        if (in.find(a) != in.end() && in.find(b) != in.end()) {
            if (oldface == NULL) {
                oldface = faces.at(i);
            }
            else {
                return;
            }
        }
    }

    // make new connections
    if (oldface == NULL) {
        return;
    }
    Face* newface = new Face();
    HalfEdge* atob = new HalfEdge(a, newface);
    HalfEdge* btoa = new HalfEdge(b, oldface);
    atob->twin = btoa;
    btoa->twin = atob;

    // loop around the half belonging to old face
    HalfEdge* current = face->edge;
    while (current->next->origin != b) {
        current = current->next;
    }
    atob->next = current->next;
    current->next = btoa;

    // loop around the half belonging to new face
    current = atob->next;
    while (current->next->origin != a) {
        current->face = newface;
        current = current->next;
    }
    btoa->next = current->next;
    current->next = atob;

    // set edges for the face
    newface->edge = atob;
    oldface->edge = btoa;
    edges.push_back(atob);
    edges.push_back(btoa);
    faces.push_back(newface);
}



void createVertex(Vertex* p1, Vertex* p2, Point lolwedontusethis) {
    //Find a face with both p1 and p2
    Face* oldface;
    for (unsigned i = 0; i < faces.size(); i++) {
        list<Vertex*> v = boundaryVertices(faces.at(i));
        if (v.find(p1) != v.end() && v.find(p2) != v.end()) {
            oldface = face;
            break;
        }
    }

    //Create the new vertex
    Vertex* v = new Vertex();
    //Create new Face which splits the current face
    Face* newface = new Face();
    //Create new HalfEdges
    HalfEdge* p1tov = new HalfEdge(p1, oldface);
    HalfEdge* vtop2 = new HalfEdge(v, oldface);
    HalfEdge* p2tov = new HalfEdge(p2, newface);
    HalfEdge* vtop1 = new HalfEdge(v, newface);
    p1tov->twin = vtop1;
    p2tov->twin = vtop2;
    vtop1->twin = p1tov;
    vtop2->twin = p2tov;
    p1tov->next = vtop2;
    p2tov->next = vtop1;

    // loop until we find p1
    HalfEdge* current = oldface->edge;
    while (current->next->origin != p1) {
        current = current->next;
    }
    p2vtop1->next = current->next;
    current->next = p1top2v;

    // start from p1 and go to p2 and make all edges in newface
    current = p2top1-vtop1->next;
    while (current->next->origin != p2) {
        current->face = newface;
        current = current->next;
    }
    current->face = newface;
    p1top2-vtop2->next = current->next;
    current->next = p2top1v;

    oldface->edge = p1top2v;
    newface->edge = p2top1vtop1;
    edges.push_back(p1top2p1tov);
    edges.push_back(p2top1p2tov);
    edges.push_back(vtop1);
    edges.push_back(vtop2);
    vertices.push_back(v);
    faces.push_back(newface);
}

/*Given an edge leaving a vertex v, this function returns the next edge leaving the vertex v. 
Note that in the vertex, we only store one leaving edge. 
This function should be used to iterate over all leaving edges of a vertex. */

HalfEdge* Vertex::nextLeaving(HalfEdge* first) {
    return(first->twin->next);
}

/*Returns the destination vertex of a HalfEdge. 
Note that we only store the source vertex of a HalfEdge. 
This function is used to return the destination vertex as well. */

Vertex* PEdge::destination() {
    return(this->next->origin);
}

//Creates and returns a new vertex at the given point location.

Vertex* DCEL:createVertex(double x, double y) {
    Vertex* v1 = new Vertex(Point(x, y));
    vertices.push_back(v1);
    return v1;
}



/*Creates an edge, i.e., two half edges, between two existing vertices. 
One of the two half edges is returned. The other half edge can be found using 
the twin attribute. Keep in mind that inserting an edge could result in creating a new face. */

HalfEdge* DCEL::createEdge(Vertex* a, Vertex* b) {
    //The exact same thing as the connectVertices function?
    Face* oldface = NULL;
    
    // find the face containing both a and b
    // if multiple faces have both, then an edge already exist
    for (int i = 0; i < faces.size(); i++) {
        list<Vertex*> in = boundaryVertices(faces[i]);
        if (in.find(a) != in.end() && in.find(b) != in.end()) {
            if (oldface == NULL) {
                oldface = faces[i];
            }
            else {
                break;
            }
        }
    }

    // make new connections
    if (oldface == NULL) {
        break;
    }
    Face* newface = new Face();
    HalfEdge* atob = new HalfEdge(a, newface);
    HalfEdge* btoa = new HalfEdge(b, oldface);
    atob->twin = btoa;
    btoa->twin = atob;

    // loop around the half belonging to old face
    HalfEdge* current = face->edge;
    while (current->next->origin != b) {
        current = current->next;
    }
    atob->next = current->next;
    current->next = btoa;

    // loop around the half belonging to new face
    current = atob->next;
    while (current->next->origin != a) {
        current->face = newface;
        current = current->next;
    }
    btoa->next = current->next;
    current->next = atob;

    // set edges for the face
    newface->edge = atob;
    oldface->edge = btoa;
    edges.push_back(atob);
    edges.push_back(btoa);
    faces.push_back(newface);
    return atob;
}

//Returns all faces that are adjacent to a vertex v.

vector<Face*> DCEL::findFaces(Vertex* a) {
    vector<Face*> adjacent;
    HalfEdge* currentEdge = a->leaving;
    do {
      adjacent.push_back(currentEdge->face);
      currentEdge = currentEdge->twin->next;
    } while(currentEdge != a->leaving)
    return adjacent;
}

//Returns true if and only if the two given vertices have a common edge between them.

bool DCEL::isConnected(Vertex* a, Vertex* b) {
    HalfEdge* currentEdge = a->leaving;
    do {
        if (currentEdge->next->origin == b) {
            return TRUE;
        }
        currentEdge = currentEdge->twin->next;
    } while(currentEdge != a->leaving)
    return FALSE;
}

/*If exists, returns the HalfEdge that has v as its source vertex and f as its face. 
If such an edge does not exist, a NULL pointer is returned. */

HalfEdge* DCEL::findIncidentEdge(Vertex* v, Face* f) {
    for(unsigned i = 0; i < edges.size(); i++) {
        HalfEdge* currentEdge = edges.at(i);
        if(currentEdge->origin == v && currentEdge->face == f) {
            return TRUE;
        }
    }
    return FALSE;
}


int main() {
    //Create the DCEL structure. Test cases not implemented due to lack of time
    
    Vertex v1 = new Vertex(Point(1, 4));
    Vertex v2 = new Vertex(Point(1, 8));
    Vertex v3 = new Vertex(Point(4, 10));
    Vertex v4 = new Vertex(Point(7, 8));
    Vertex v5 = new Vertex(Point(7, 4));
    Vertex v6 = new Vertex(Point(4, 2));
    
    HalfEdge v1tov2 = new HalfEdge(&v1);
    HalfEdge v2tov3 = new HalfEdge(&v2);
    HalfEdge v3tov4 = new HalfEdge(&v3);
    HalfEdge v4tov5 = new HalfEdge(&v4);
    HalfEdge v5tov6 = new HalfEdge(&v5);
    HalfEdge v6tov1 = new HalfEdge(&v6);
    
    HalfEdge v2tov1 = new HalfEdge(&v2);
    HalfEdge v3tov2 = new HalfEdge(&v3);
    HalfEdge v4tov3 = new HalfEdge(&v4);
    HalfEdge v5tov4 = new HalfEdge(&v5);
    HalfEdge v6tov5 = new HalfEdge(&v6);
    HalfEdge v1tov6 = new HalfEdge(&v1);
    
    v1tov2->twin = v2tov1;
    v2tov1->twin = v1tov2;
    v2tov3->twin = v3tov2;
    v3tov2->twin = v2tov3;
    v3tov4->twin = v4tov3;
    v4tov3->twin = v3tov4;
    v4tov5->twin = v5tov4;
    v5tov4->twin = v4tov5;
    v5tov6->twin = v6tov5;
    v6tov5->twin = v5tov6;
    v6tov1->twin = v1tov6;
    v1tov6->twin = v6tov1;
    
    v1tov2->next = v2tov3;
    v2tov3->next = v3tov4;
    v3tov4->next = v4tov5;
    v4tov5->next = v5tov6;
    v5tov6->next = v6tov1;
    v6tov1->next = v1tov2;
    v2tov1->next = v1tov6;
    v1tov6->next = v6tov5;
    v6tov5->next = v5tov4;
    v5tov4->next = v4tov3;
    v4tov3->next = v3tov2;
    v3tov2->next = v2tov1;
    
    Face f1 = new Face(&v1tov2);
    Face f2 = new Face(&v2tov1);
    
    v1tov2->face = &f1;
    v2tov1->face = &f2;
    v2tov3->face = &f1;
    v3tov2->face = &f2;
    v3tov4->face = &f1;
    v4tov3->face = &f2;
    v4tov5->face = &f1;
    v5tov4->face = &f2;
    v5tov6->face = &f1;
    v6tov5->face = &f2;
    v6tov1->face = &f1;
    v1tov6->face = &f2;
    
    DCEL total;
    total.vertices.push_back(&v1);
    total.vertices.push_back(&v2);
    total.vertices.push_back(&v3);
    total.vertices.push_back(&v4);
    total.vertices.push_back(&v5);
    total.vertices.push_back(&v6);
    
    total.edges.push_back(&v1tov2);
    total.edges.push_back(&v2tov3);
    total.edges.push_back(&v3tov4);
    total.edges.push_back(&v4tov5);
    total.edges.push_back(&v5tov6);
    total.edges.push_back(&v6tov1);
    total.edges.push_back(&v2tov1);
    total.edges.push_back(&v1tov6);
    total.edges.push_back(&v6tov5);
    total.edges.push_back(&v5tov4);
    total.edges.push_back(&v4tov3);
    total.edges.push_back(&v3tov2);
    
    total.faces.push_back(&f1);
    total.faces.push_back(&f2);
    
    //Implement test cases for the functions above
    
    return 0;
}
// See: http://www.roguetemple.com/z/hyper/rogueviz.php

namespace rogueviz {
  using namespace hr;

  extern bool on;
  string describe(shmup::monster *m);
  void describe(cell *c);
  void activate(shmup::monster *m);
  void drawVertex(const transmatrix &V, cell *c, shmup::monster *m);
  bool virt(shmup::monster *m);
  void turn(int delta);
  void drawExtra();
  void fixparam();
  int readArgs();
  void close();
  void mark(cell *c);
  void showMenu();
  string makehelp();

  void init();
  
  struct edgetype {
    double visible_from;
    unsigned color;
    string name;
    };
  
  static const unsigned DEFAULT_COLOR = 0x471293B5;

  extern edgetype default_edgetype;
  
  vector<shared_ptr<edgetype>> edgetypes;
    
  struct edgeinfo {
    int i, j;
    double weight, weight2;
    vector<glvertex> prec;
    cell *orig;
    int lastdraw;
    edgetype *type;
    edgeinfo(edgetype *t) { orig = NULL; lastdraw = -1; type = t; }
    };
  
  struct colorpair {
    int color1, color2;
    char shade;
    colorpair(int col = 0xC0C0C0FF) { shade = 0; color1 = col; }
    };
  
  struct vertexdata {
    vector<pair<int, edgeinfo*> > edges;
    string name;
    colorpair cp;
    edgeinfo *virt;
    bool special;
    int data;
    string *info;
    shmup::monster *m;
    vertexdata() { virt = NULL; m = NULL; info = NULL; special = false; }
    };
  
  extern vector<vertexdata> vdata;
 
  void storeall(int from = 0);

  namespace anygraph {
    extern double R, alpha, T;
    extern vector<pair<double, double> > coords;
    
    void fixedges();
    void read(string fn, bool subdiv = true, bool doRebase = true, bool doStore = true);
    extern int N;
    }
  
  extern bool showlabels;

  extern bool rog3;
  extern bool rvwarp;
#if CAP_TOUR
  namespace rvtour {
    extern tour::slide rvslides[];
    }
#endif

  namespace kohonen {
    extern int samples;
    int showsample(int id);
    int showsample(string id);
    void describe(cell *c);
    void steps();
    void showMenu();
    bool handleMenu(int sym, int uni);
    }
  
  namespace staircase {
    extern bool on;
    void showMenu();
    void make_staircase();
    }
  
  namespace banachtarski {
    extern bool on;
    void init_bantar();
    void bantar_anim();    
    extern bool bmap;
    extern void init_bantar_map();
    }
}


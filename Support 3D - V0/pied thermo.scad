module petit_thermo() {
    difference() {
        rotate([70,0,0]) difference() {
            union() {
// Bloc général                
                translate([0,-2,0]) cube([46,41,16], center=true);
// Pied arrière
                translate([0,-8,-14.5]) cube([2,30,15], center=true);
// Pieds latéraux
                for (x=[-22.5,-11.25,0,11.25,22.5]) translate([x,-27,0]) cube([1,10,16], center=true);
// Plein face basse avant
                translate([0,-27,7.5]) cube([46,10,1], center=true);
            }
            
// Évidement moitié haute
            translate([0,25/2,1]) cube([50,25,16], center=true);
            
            union() {
// Percement avant
                translate([0,0,7]) cube([39,39,3], center=true);
// Arrondis avant
                for (i=[-1,1]) translate([i*22,-2.5,5]) rotate([0,0,(i+1)*45]) difference() { 
                    cube(5);
                    cylinder(h=12,d=5, center=true, $fn=40);
                }
            }

// Évidement Thermo
            cube([43.5,44,14], center=true);

// Arrondis arrière
            for (i=[-1,1]) translate([i*13,8.5,-15]) rotate([0,0,(-i+1)*45]) difference() { 
                cube(20);
                cylinder(h=45,d=20, center=true, $fn=40);
            }
        
// Trou capteur
            translate([0,25,-7.5]) cylinder(h=3, d=20, center=true);
        }

// Plan arrière
        translate([0,19.907,-16.155]) cube([3,20,40], center=true);

// Découpe Dessous
        translate([0,0,-32.5-1]) cube([50,50,20], center=true);
        
    }
};

// petit_thermo();

*rotate([20,0,0]) translate([0,6.5,29]) cube([110,10,55], center=true);

difference() {
    rotate([20,0,0]) {
// Plaque arrière
        hull() {
            translate([0,0.5,0]) cube([80,1,1], center=true);
            for (x=[-30,30]) translate([x,0.5,30]) rotate([90,0,0]) cylinder(h=1, d=20, center=true, $fn=60);
        }
// Bas arrondi        
        translate([0,6.5,1]) difference() {
            cube([80,12,2], center=true);
            translate([0,0,1]) rotate([0,90,0]) scale([0.2,1,1]) cylinder(h=82, d=11, center=true, $fn=60);
    };
// Pieds dessous
        translate([0,6,-2.5]) cube([80,12+1,5], center=true);
        *for (x=[-39.5,-19.25,0,19.25, 39.5]) translate([x,6,-2.5]) cube([1,12,5], center=true);
// Cache avant
        *translate([0,12,-2.5]) cube([80,1,5], center=true);
// Pieds arrière
        for (x=[-39.5,0,39.5]) translate([x,-9.5,15]) cube([1,20,30], center=true);
    translate([0,-4.5,7.5/2]) cube([80,11,7.5], center=true);
    };
// Masquage des pieds
    translate([0,0,-5]) cube([85,50,10], center=true);
    translate([0,-20.265,8.19]) cube([85,20,40], center=true);
};




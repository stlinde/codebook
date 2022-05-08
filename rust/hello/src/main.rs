fn greet_world() {
    println!("Hello, world!");

    let southern_germany = "Grüß Gott";
    let denmark = "Goddag";

    let regions =  [southern_germany, denmark];

    for region in regions.iter() { 
        println!("{}", &region);
    }
}

fn main() {
    greet_world();
}

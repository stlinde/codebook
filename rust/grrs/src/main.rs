#![allow(unused)]

use clap::Parser;

#[derive(Parser)]
struct CLI {
    // The pattern to look for
    pattern: String,
    // The path to the file to read.
    path: std::path::PathBuf,
}
fn main() {
    let args = CLI::parse();

    let content = std::fs::read_to_string(&args.path)
        .expect("Could not read file");

    for line in content.lines() {
        if line.contains(&args.pattern) {
            println!("{}", line);
        }
    }
}

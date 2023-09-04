import argparse

def cli():
    parser = argparse.ArgumentParser(description='CLI Example')
    parser.add_argument('--name', help='Your name')
    parser.add_argument('--age', help='Your age')
    args = parser.parse_args()
    print(f'Name: {args.name}')
    print(f'Age: {args.age}')

if __name__ == '__main__':
    cli()
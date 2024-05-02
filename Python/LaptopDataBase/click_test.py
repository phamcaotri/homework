import click

class CLI:
    def __init__(self):
        self.cli = click.Group()

    def hello(self):
        click.echo('Hello World!')

    def prompt(self):
        command = click.prompt('>>', type=str)
        
        commands = {
            'hello': self.hello
        }

        func = commands.get(command, None)

        if func is not None:
            func()
        else:
            click.echo('Command not found')



if __name__ == '__main__':
    cli = CLI()
    cli.prompt()
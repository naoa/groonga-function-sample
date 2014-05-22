# Sample groonga function

## Install

Install libgroonga-dev.

Build this function.

    % ./configure
    % make
    % sudo make install

## Usage

Register `function/strlen`:

    % groonga DB
    > register function/strlen

Now, you can use `strlen` function

    > select Entries --output_columns 'strlen(title)' --command_version 2
    [
      [
        0,
        0.0,
        0.0
      ],
      [
        [
          [
           1
          ],
          [
            [
              "strlen",
              "Object"
            ],
          ],
          [
           17
          ]
        ],
      ]
    ]

## License

Public domain. You can copy and modify this project freely.

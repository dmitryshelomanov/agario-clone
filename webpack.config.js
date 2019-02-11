const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')


const { NODE_ENV = 'development' } = process.env

module.exports = {
  mode: NODE_ENV,
  devtool: 'inline-source-map',
  entry: './lib/js/src/index.bs.js',
  output: {
    path: path.resolve(__dirname, 'dist'),
    filename: 'bundle.js',
  },
  plugins: [
    new HtmlWebpackPlugin({
      title: 'Agario clone',
      template: './index.html',
    }),
  ],
  devServer: {
    contentBase: './dist',
  },
}
